#ifndef MANDELBROT_SET_BMPHEADER_H
#define MANDELBROT_SET_BMPHEADER_H

#include <stdint.h>

#pragma pack(1)

typedef struct {
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
    uint32_t header_size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bits;
    uint32_t compression;
    uint32_t imagesize;
    int32_t xresolution;
    int32_t yresolution;
    uint32_t ncolors;
    uint32_t importantcolours;
} BMP_Header;

#endif //MANDELBROT_SET_BMPHEADER_H
