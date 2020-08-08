cmake_minimum_required(VERSION 3.5)

project(HistogramEqualization LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(Qt5_DIR /Users/gksbrandon/Qt/5.15.0/clang_64/lib/cmake/Qt5)
set(Qt5Core_DIR /Users/gksbrandon/Qt/5.15.0/clang_64/lib/cmake/Qt5Core) 
set(DQt5Gui_DIR /Users/gksbrandon/Qt/5.15.0/clang_64/lib/cmake/Qt5Gui) 
set(DQt5Widgets_DIR /Users/gksbrandon/Qt/5.15.0/clang_64/lib/cmake/Qt5Widgets)

enable_testing()
add_subdirectory(googletest)
add_subdirectory(test)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(OpenCV REQUIRED )

# if(ANDROID)
  add_library(HistogramEqualization STATIC
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    HistogramEqualization.cpp
    HistogramEqualization.h
  )
# else()
   add_executable(HistogramEqualizationExe
     main.cpp
     mainwindow.cpp
     mainwindow.h
     mainwindow.ui
     HistogramEqualization.cpp
     HistogramEqualization.h
   )
# endif()

# add_library(HistogramEqualization STATIC ${Sources} ${Headers})

target_link_libraries(HistogramEqualization PRIVATE Qt5::Widgets ${OpenCV_LIBS})
target_link_libraries(HistogramEqualizationExe PRIVATE Qt5::Widgets ${OpenCV_LIBS})