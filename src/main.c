#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "../include/bmpfile.h"
#include "../include/mandelbrot.h"
#include "../include/zoom.h"

int main(void) {
    int width = 2000, height = 2000;
    double centerX = -0.75, centerY = 0.0, scale = 1.0;

    BMP_Image *image = BMP_init(width, height);
    ZOOM zoom = {centerX, centerY, scale};

    mandelbrot(image, &zoom);

    if (!BMP_save(image, "mandelbrot_24bit.bmp")) {
        fprintf(stderr, "Failed to save BMP image.\n");
        BMP_destroy(image);
        return EXIT_FAILURE;
    }

    BMP_destroy(image);

    return 0;
}
