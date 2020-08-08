#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "HistogramEqualization.h"
#include <iostream>

HistogramEqualization he;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_selectImage_clicked()
{
    // Load the image and transform to grayscale
    QString fileName = QFileDialog::getOpenFileName(this, "Choose image");
    if (QString::compare(fileName, QString()) == 0)
    {
        std::cout << "Error in loading image / No image chosen" << std::endl;
        return;
    }
    cv::Mat image = cv::imread(fileName.toStdString(), cv::IMREAD_GRAYSCALE);
    he.SetImage(image);

    // Generate the histogram
    he.SetIntensityHistogram(image, he.GetHistogram());

    // Display the Image
    cv::namedWindow("Image");
    cv::imshow("Image", image);

    // Display the Histogram
    he.DisplayHistogram(he.GetHistogram(), "Histogram");
}

void MainWindow::on_processImage_clicked()
{
    // Generate the size of image
    int size = he.GetImage().rows * he.GetImage().cols;
    float alpha = 255.0/size;

    // Calculate the probability of each intensity
    float PrRk[256];
    he.ProbIntensity(PrRk, he.GetHistogram(), size);

    // Generate cumulative frequency histogram
    int cumhistogram[256];
    he.SetCumulativeHistogram(he.GetHistogram(), cumhistogram);

    // Scale the histogram
    int Sk[256];
    for (int i = 0; i < 256; i++)
    {
        Sk[i] = cvRound((double)cumhistogram[i] * alpha);
    }

    // Generate the equalized histogram
    float PsSk[256];
    for (int i = 0; i < 256; i++)
    {
        PsSk[i] = 0;
    }

    for (int i = 0; i < 256; i++)
    {
        PsSk[Sk[i]] += PrRk[i];
    }

    int final[256];
    for (int i = 0; i < 256; i++)
        final[i] = cvRound(PsSk[i]*255);

    // Generate the equalized image
    cv::Mat new_image = he.GetImage().clone();

    for (int y = 0; y < he.GetImage().rows; y++)
        for (int x = 0; x < he.GetImage().cols; x++)
            new_image.at<uchar>(y, x) = cv::saturate_cast<uchar>(Sk[he.GetImage().at<uchar>(y, x)]);

    // Display the Image
    cv::namedWindow("Image");
    cv::imshow("Image", new_image);

    // Display the Histogram
    he.DisplayHistogram(final, "Histogram");
}
