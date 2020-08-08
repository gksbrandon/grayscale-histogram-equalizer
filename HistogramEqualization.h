#ifndef HISTOGRAMEQUALIZATION_H
#define HISTOGRAMEQUALIZATION_H

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class HistogramEqualization {
private:
    cv::Mat image;
    int histogram[256];

public:
    HistogramEqualization(); 
    cv::Mat GetImage();
    void SetImage(cv::Mat image);
    int* GetHistogram();
    void SetHistogram(int* histogram);
    void SetIntensityHistogram(cv::Mat image, int histogram[]);
    static void ProbIntensity(float PrRk[], int histogram[], int size);
    static void SetCumulativeHistogram(int histogram[], int cumhistogram[]);
    void DisplayHistogram(int histogram[], const char* name);
};

#endif /* HISTOGRAMEQUALIZATION_H */
