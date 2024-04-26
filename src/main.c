#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "../include/bmpfile.h"
#include "../include/mandelbrot.h"

int main(void) {
    int width = 2000, height = 2000;
    BMP_Image *image = BMP_init(width, height);

    mandelbrot(image);

    if (!BMP_save(image, "mandelbrot_24bit.bmp")) {
        fprintf(stderr, "Failed to save BMP image.\n");
        BMP_destroy(image);
        return EXIT_FAILURE;
    }

    BMP_destroy(image);

    return 0;
}
