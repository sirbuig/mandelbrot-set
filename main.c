#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "structs.h"
#include "bmpfile.h"

int main(void) {
    int width = 400, height = 300;
    BMP_Image *image = BMP_init(width, height);
//    if (!image) {
//        fprintf(stderr, "Failed");
//        return EXIT_FAILURE;
//    }
//
//    printf("%d\n", image->data_size);
//    for (unsigned int y = 0; y < image->height; y++) {
//        for (unsigned int x = 0; x < image->width; x++) {
//            unsigned int index = y * image->width + x;
//            RGB pixel = image->data[index];
//            printf("(%3d, %3d, %3d) ", pixel.red, pixel.green, pixel.blue);
//        }
//        printf("\n");
//    }
    for (unsigned int i = 0; i < (image->width * image->height); i++) {
        image->data[i].red = 128;
        image->data[i].green = 0;
        image->data[i].blue = 128;
    }

    if (!BMP_save(image, "output.bmp")) {
        fprintf(stderr, "Failed to save BMP image.\n");
        BMP_destroy(image);
        return EXIT_FAILURE;
    }

    BMP_destroy(image);

    return 0;
}
