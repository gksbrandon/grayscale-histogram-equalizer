# Grayscale Histogram Equalizer

## To Build
Clone the repo and submodules
```
git clone git@github.com:gksbrandon/grayscale-histogram-equalizer.git --recurse-submodules
```
file: ![clone](https://github.com/gksbrandon/grayscale-histogram-equalizer/blob/master/readme-gifs/clone.gif)

Create the build directory, then build the application and tests
```
cd grayscale-histogram-equalizer
mkdir build
cd build
cmake ..
make
```
file: ![build](https://github.com/gksbrandon/grayscale-histogram-equalizer/blob/master/readme-gifs/build.gif)
file: ![build2](https://github.com/gksbrandon/grayscale-histogram-equalizer/blob/master/readme-gifs/build2.gif)

## To Run Tests
```
cd build/test
./HistogramEqualizationTests
```
file: ![test](https://github.com/gksbrandon/grayscale-histogram-equalizer/blob/master/readme-gifs/test.gif)

## To Run Application
```
cd build
./HistogramEqualizationExe
```
file: ![run](https://github.com/gksbrandon/grayscale-histogram-equalizer/blob/master/readme-gifs/run.gif)
