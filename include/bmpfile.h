#ifndef MANDELBROT_SET_BMPFILE_H
#define MANDELBROT_SET_BMPFILE_H

#include "bmpimage.h"

BMP_Image *BMP_init(int width, int height);

int BMP_save(const BMP_Image *image, const char *filename);

void BMP_destroy(BMP_Image *image);

#endif //MANDELBROT_SET_BMPFILE_H
