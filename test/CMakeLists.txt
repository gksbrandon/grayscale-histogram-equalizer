cmake_minimum_required(VERSION 3.8)

set(This HistogramEqualizationTests)
set(Sources
    HistogramEqualizationTests.cpp
)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(OpenCV REQUIRED )

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    gtest_main
    Qt5::Widgets 
    ${OpenCV_LIBS}
    HistogramEqualization
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
