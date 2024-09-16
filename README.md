# mandelbrot-set

This project generates a Mandelbrot fractal and saves it as a `.bmp` file.

## Commands

Clone the project

```
git clone https://github.com/sirbuig/mandelbrot-set.git
```

Make sure that `cmake` is installed and that you have a C compiler, such as `gcc`.

Create the build directory

```
mkdir cmake-build
cd cmake-build
```

Run CMake to generate the build files

```
cmake ..
```

Compile the project

```
cmake --build .
```

Run the compiled program

```
./mandelbrot_set
```

After running, a file called mandelbrot_24bit.bmp should appear in the current folder. This file contains the image of the Mandelbrot fractal in BMP format.

## Why BMP?

I found it interesting to use especially because the image is pixel-generated. It's simple to grasp and I had fun understanding how some image formats store the bytes under the hood.

This is the resource I used: https://engineering.purdue.edu/ece264/16au/hw/HW13.

## Results

I still want to continue the project, but I'm taking a break from it. These are some of the results so far:

1. Original

```cpp
int width = 2000, height = 2000;
double centerX = -0.75, centerY = 0.0, scale = 1.0;
```

![orange-original-fractal](showcase/1.bmp)

2. Smaller scale

```cpp
double centerX = -0.75, centerY = 0.0, scale = 0.5;
```

![smaller-fractal](showcase/2.bmp)