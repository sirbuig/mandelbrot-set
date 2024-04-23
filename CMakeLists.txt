cmake_minimum_required(VERSION 3.28)
project(mandelbrot_set C)

set(CMAKE_C_STANDARD 11)

add_executable(mandelbrot_set src/main.c
        src/mandelbrot.c
        include/mandelbrot.h
        include/bmpheader.h
        include/bmpimage.h
        src/bmpfile.c
        include/bmpfile.h
        include/rgb.h
)
