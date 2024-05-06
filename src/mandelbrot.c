#include <malloc.h>
#include "../include/mandelbrot.h"
#include "../include/rgb.h"

#define MIN_X -2.00
#define MAX_X 0.47
#define MIN_Y -1.12
#define MAX_Y 1.12
#define MAX_ITERATION 1000

void mandelbrot(BMP_Image *img, const ZOOM *zoom) {
    RGB *palette = (RGB *) malloc(MAX_ITERATION * sizeof(RGB));
    for (unsigned int c = 0; c < MAX_ITERATION; c++) {
        palette[c].red = (unsigned char) (255 * c / MAX_ITERATION);
        palette[c].green = 125;
        palette[c].blue = (unsigned char) (255 * (MAX_ITERATION - c) / MAX_ITERATION);
    }

    double rangeX = 2.47 / zoom->scale;
    double rangeY = 2.24 / zoom->scale;

    for (unsigned int i = 0; i < img->height; i++) {
        for (unsigned int j = 0; j < img->width; j++) {
            double x0 = (j / (double)img->width) * rangeX + (zoom->centerX - rangeX / 2);
            double y0 = (i / (double)img->height) * rangeY + (zoom->centerY - rangeY / 2);

            double x, y, aux;
            unsigned int iteration = 0;

            x = y = 0.0;
            while (x * x + y * y <= 4 && iteration < MAX_ITERATION) {
                aux = x * x - y * y + x0;
                y = 2 * x * y + y0;
                x = aux;
                iteration += 1;
            }

            RGB color = palette[(iteration == MAX_ITERATION) ? MAX_ITERATION - 1 : iteration];
            img->data[i * img->width + j] = color;
        }
    }

    free(palette);
}
