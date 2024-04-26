#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "../include/bmpfile.h"

int main(void) {
    int width = 100, height = 100;
    BMP_Image *image = BMP_init(width, height);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * width + x;
            image->data[index].blue = 128;
            image->data[index].green = 0;
            image->data[index].red = 128;
        }
    }

    if (!BMP_save(image, "test4.bmp")) {
        fprintf(stderr, "Failed to save BMP image.\n");
        BMP_destroy(image);
        return EXIT_FAILURE;
    }

    BMP_destroy(image);

    return 0;
}
