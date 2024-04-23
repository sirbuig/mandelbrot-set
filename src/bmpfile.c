#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "../include/bmpfile.h"

#define MAGIC_VALUE 0x4D42
#define BITS_PER_PIXEL 24
#define NUM_PLANE 1
#define COMPRESSION 0
#define BITS_PER_BYTE 8
#define BMP_HEADER_SIZE 40
#define PPM 2835

BMP_Image *BMP_init(int width, int height) {
    BMP_Image *img = malloc(sizeof(BMP_Image));
    if (!img) {
        return NULL;
    }

    int bytes_per_pixel = BITS_PER_PIXEL / BITS_PER_BYTE; // 24-bit BMP

    img->header.type = MAGIC_VALUE;
    img->header.size = sizeof(BMP_Header) + (width * height * sizeof(RGB));
    img->header.reserved1 = 0;
    img->header.reserved2 = 0;
    img->header.offset = sizeof(BMP_Header);
    img->header.header_size = BMP_HEADER_SIZE;
    img->header.width = width;
    img->header.height = height;
    img->header.planes = 1;
    img->header.bits = BITS_PER_PIXEL;
    img->header.compression = 0;
    img->header.imagesize = width * height * sizeof(RGB);
    img->header.xresolution = PPM;
    img->header.yresolution = PPM;
    img->header.ncolors = 0;
    img->header.importantcolours = 0;

    img->data_size = width * height * sizeof(RGB);
    img->width = width;
    img->height = height;
    img->data = malloc(img->data_size);
    if (!img->data) {
        BMP_destroy(img);
        return NULL;
    }
    memset(img->data, 0, img->data_size);
    return img;
}

int BMP_save(const BMP_Image *img, const char *filename) {
    FILE *fptr = NULL;
    fptr = fopen(filename, "w");
    if (fptr == NULL) {
        return 0;
    }
    if (fwrite(&(img->header), sizeof(BMP_Header), 1, fptr) != 1) {
        fclose(fptr);
        return 0;
    }
    if (fwrite(img->data, sizeof(RGB), img->width * img->height, fptr) != (img->width * img->height)) {
        fclose(fptr);
        return 0;
    }
    fclose(fptr);
    return 1;
}

void BMP_destroy(BMP_Image *img) {
    free(img->data);
    free(img);
}