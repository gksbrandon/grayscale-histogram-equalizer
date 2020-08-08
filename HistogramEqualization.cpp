#include "HistogramEqualization.h"

HistogramEqualization::HistogramEqualization() {
    // Initialize Array
    for (int i = 0; i < 256; i++) {
        this->histogram[i] = 0;
    }
}

cv::Mat HistogramEqualization::GetImage()
{
    return this->image;
}
void HistogramEqualization::SetImage(cv::Mat image)
{
    this->image = image;
}

int* HistogramEqualization::GetHistogram() {
    return this->histogram;
}

void HistogramEqualization::SetHistogram(int* histogram) {
    for (int i = 0; i < 256; i++) {
        this->histogram[i] = histogram[i];
    }
}

void HistogramEqualization::SetIntensityHistogram(cv::Mat image, int histogram[])
{
    // Initialize all intensity values to 0
    for (int i = 0; i < 256; i++)
    {
        histogram[i] = 0;
    }

    // Calculate the no of pixels for each intensity values
    for (int y = 0; y < image.rows; y++)
        for (int x = 0; x < image.cols; x++)
            histogram[(int)image.at<uchar>(y, x)]++;
}

void HistogramEqualization::ProbIntensity(float PrRk[], int histogram[], int size)
{
    // Calculates the probability of intensity based on intensity / size
    for (int i = 0; i < 256; i++)
    {
        PrRk[i] = (double)histogram[i] / size;
    }

}

void HistogramEqualization::SetCumulativeHistogram(int histogram[], int cumulativeHistogram[])
{
    // Calculates cumulative histogram
    cumulativeHistogram[0] = histogram[0];

    for (int i = 1; i < 256; i++)
    {
        cumulativeHistogram[i] = histogram[i] + cumulativeHistogram[i-1];
    }
}

void HistogramEqualization::DisplayHistogram(int histogram[], const char* name)
{
    // Copy to a Temp Histogram
    int histogramTemp[256];
    for (int i = 0; i < 256; i++)
    {
        histogramTemp[i]=histogram[i];
    }

    // Draw the histogram
    int hist_w = 900; int hist_h = 400;
    int bin_w = cvRound((double)hist_w/256);
    cv::Mat histImage(hist_h, hist_w, CV_8UC1, cv::Scalar(255, 255, 255));

    // Find the maximum intensity element from histogram
    int max = histogramTemp[0];
    for (int i = 1; i < 256; i++) {
        if (max < histogramTemp[i]) {
            max = histogramTemp[i];
        }
    }

    // Normalize the histogram between 0 and histImage.rows
    for (int i = 0; i < 256; i++) {
        histogramTemp[i] = ((double)histogramTemp[i]/max)*histImage.rows;
    }

    // Draw the intensity line for histogram
    for (int i = 0; i < 256; i++)
    {
        line(histImage, cv::Point(bin_w*(i), hist_h),
            cv::Point(bin_w*(i), hist_h - histogramTemp[i]),
            cv::Scalar(0, 0, 0), 1, 8, 0);
    }

    // display histogram
    cv::namedWindow(name);
    cv::imshow(name, histImage);
}
