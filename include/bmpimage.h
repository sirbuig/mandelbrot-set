#ifndef MANDELBROT_SET_BMPIMAGE_H
#define MANDELBROT_SET_BMPIMAGE_H

#include "bmpheader.h"
#include "rgb.h"

typedef struct {
    BMP_Header header;
    unsigned int data_size;
    unsigned int width;
    unsigned int height;
    RGB *data;
} BMP_Image;

#endif //MANDELBROT_SET_BMPIMAGE_H
