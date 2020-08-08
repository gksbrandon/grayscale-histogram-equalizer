#include <gtest/gtest.h>
#include <../HistogramEqualization.h>
#include <iostream>

TEST(HistogramEqualizationTests, CheckHistogramEqualization) {
    HistogramEqualization he;
    for (int i = 0; i < 256; i++) {
        ASSERT_EQ(he.GetHistogram()[i], 0);
    }
}

TEST(HistogramEqualizationTests, GetImage) {
    HistogramEqualization he;
    ASSERT_EQ(he.GetImage().rows, 0);
    ASSERT_EQ(he.GetImage().cols, 0);
}

TEST(HistogramEqualizationTests, SetImage) {
    HistogramEqualization he;
    cv::Mat image;
    image.rows = 10;
    image.cols = 20;

    he.SetImage(image);

    ASSERT_EQ(he.GetImage().rows, image.rows);
    ASSERT_EQ(he.GetImage().cols, image.cols);
}

TEST(HistogramEqualizationTests, GetHistogram) {
    HistogramEqualization he;
    int* pa = he.GetHistogram();
    ASSERT_EQ(pa, he.GetHistogram());
}

TEST(HistogramEqualizationTests, SetHistogram) {
    HistogramEqualization he;
    int histogram[256];
    for (int i = 0; i < 256; i++) {
        histogram[i] = i;
    }

    he.SetHistogram(histogram);
    
    for (int i = 0; i < 256; i++) {
        ASSERT_EQ(he.GetHistogram()[i], histogram[i]);
    }
}

TEST(HistogramEqualizationTests, ProbIntensity) {
    int size = 10;

    float PrRk[256];
    for (int i = 0; i < 256; i++) {
        PrRk[i] = 0;
    }

    int histogram[256];
    for (int i = 0; i < 256; i++) {
        histogram[i] = i;
    }

    HistogramEqualization::ProbIntensity(PrRk, histogram, size);
    for (int i = 0; i < 256; i++) {
        ASSERT_EQ(PrRk[i], (float)histogram[i] / size);
    }
}

TEST(HistogramEqualizationTests, SetCumulativeHistogram) {
    int histogram[256];
    for (int i = 0; i < 256; i++) {
        histogram[i] = i;
    }

    int cumulativeHistogram[256];
    for (int i = 0; i < 256; i++) {
        cumulativeHistogram[i] = 0;
    }

    HistogramEqualization::SetCumulativeHistogram(histogram, cumulativeHistogram);

    ASSERT_EQ(cumulativeHistogram[0], histogram[0]);
    for (int i = 1; i < 256; i ++) {
        ASSERT_EQ(cumulativeHistogram[i], histogram[i] + cumulativeHistogram[i - 1]);
    }
}