cmake_minimum_required(VERSION 3.28)
project(mandelbrot_set C)

set(CMAKE_C_STANDARD 11)

add_executable(mandelbrot_set main.c
        mandelbrot.c
        mandelbrot.h
        structs.h
        bmpheader.h
        bmpimage.h
        bmpfile.c
        bmpfile.h
        rgb.h
)
