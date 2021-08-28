#include <stdio.h>
#include <stdint.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "librocket.h"

// #define COMPRESSED_SIZE 0x82
// #define DECOMPRESSED_SIZE 0xBA

// uint8_t original[COMPRESSED_SIZE] = {
//     0x00, 0x00, 0x08, 0x01, 0x00, 0x3F, 0x8F, 0x81,
//     0xB7, 0x00, 0xFF, 0xEB, 0xFF, 0x80, 0x00, 0x00,
//     0x00, 0x04, 0x8E, 0x01, 0x82, 0xFF, 0xEB, 0x00,
//     0x03, 0x03, 0x01, 0x82, 0x06, 0x02, 0x01, 0xB8,
//     0x06, 0x03, 0x01, 0x06, 0x03, 0x03, 0x02, 0x01,
//     0x83, 0x0E, 0x0F, 0xFD, 0x00, 0x00, 0x02, 0x00,
//     0x02, 0x00, 0x02, 0x0F, 0xFD, 0xFC, 0x02, 0x82,
//     0x01, 0x84, 0x03, 0x06, 0x06, 0x84, 0x02, 0x84,
//     0x08, 0x0F, 0x01, 0x2F, 0x24, 0xFF, 0x32, 0x17,
//     0x41, 0x01, 0x00, 0x16, 0x01, 0xDA, 0x00, 0x6D,
//     0x03, 0x1D, 0x81, 0x01, 0xC1, 0x07, 0x13, 0x41,
//     0x03, 0x81, 0x05, 0x04, 0x02, 0x80, 0x01, 0xC2,
//     0x3F, 0x35, 0x04, 0xF3, 0x3C, 0x87, 0x5B, 0x54,
//     0x3E, 0x07, 0x82, 0x3F, 0x26, 0x41, 0x40, 0x27,
//     0x41, 0x07, 0x00, 0x00, 0x77, 0x06, 0x08, 0x04,
//     0x00, 0x09, 0x02, 0x08, 0x00, 0x20, 0x00, 0x62,
//     0x0D, 0x00
// };

#define COMPRESSED_SIZE 0xD8
#define DECOMPRESSED_SIZE 0x180

uint8_t original[COMPRESSED_SIZE] = {
  0x1c, 0x00, 0x00, 0x00, 0x00, 0xc1, 0x01, 0x84, 
  0x03, 0x08, 0x01, 0x22, 0x82, 0x06, 0x07, 0x04, 
  0x77, 0x76, 0x64, 0x20, 0x09, 0x88, 0x97, 0x44, 
  0x76, 0x03, 0x41, 0x7b, 0xa9, 0x99, 0x0e, 0x06, 
  0x06, 0xcc, 0x02, 0xbb, 0xbb, 0xbb, 0xa9, 0x74, 
  0x10, 0x12, 0x06, 0xee, 0x01, 0xdc, 0xa7, 0x61, 
  0x0d, 0xed, 0xdc, 0xcd, 0x16, 0x06, 0x00, 0x4f, 
  0xff, 0xee, 0xee, 0x74, 0xce, 0xca, 0x76, 0x80, 
  0x08, 0x47, 0x1e, 0xec, 0x97, 0x7f, 0xff, 0xfe, 
  0xed, 0xa0, 0x1e, 0x02, 0x60, 0x1f, 0x41, 0xaf, 
  0xff, 0xfd, 0xcc, 0x00, 0x08, 0x0b, 0xfd, 0xb9, 
  0x92, 0x22, 0x45, 0x20, 0x0d, 0xff, 0x36, 0xec, 
  0xbf, 0x05, 0x02, 0x26, 0x41, 0xa2, 0x27, 0x41, 
  0x03, 0x02, 0xb6, 0x08, 0xaf, 0xff, 0xfe, 0xc1, 
  0x2a, 0x45, 0xce, 0xff, 0xff, 0x0a, 0xff, 0xbf, 
  0xff, 0xfe, 0x08, 0x03, 0xa0, 0x08, 0x03, 0xff, 
  0x04, 0xdd, 0xdf, 0xff, 0xff, 0xfc, 0x20, 0x46, 
  0xef, 0xcb, 0x06, 0x97, 0x40, 0x7f, 0xff, 0xff, 
  0x18, 0x03, 0x20, 0x04, 0xff, 0x2b, 0xfd, 0xd2, 
  0x39, 0x49, 0xb0, 0x3c, 0x41, 0x0d, 0x05, 0x01, 
  0x30, 0x07, 0x0a, 0xff, 0xff, 0xfe, 0xc2, 0x41, 
  0x49, 0xc9, 0x3b, 0x02, 0x9f, 0x2e, 0xff, 0xff, 
  0x46, 0x07, 0x1c, 0x17, 0x41, 0x27, 0x46, 0x4b, 
  0x41, 0xff, 0x30, 0xca, 0x61, 0x08, 0x43, 0x4e, 
  0x08, 0x04, 0xdf, 0xff, 0xfe, 0x74, 0xca, 0x48, 
  0x87, 0x2a, 0xc1, 0x13, 0xc2, 0x04, 0x53, 0x8b, 
  0x47, 0xbb, 0x40, 0xb4, 0x5a, 0x14, 0x00, 0x00,
};



// #define COMPRESSED_SIZE 209
// #define DECOMPRESSED_SIZE 0x180

// uint8_t original[COMPRESSED_SIZE] = {
//   0x48, 0x00, 0x00, 0x53, 0x01, 0x22, 0x06, 0x07, 
//   0x04, 0x77, 0x76, 0x24, 0x64, 0x20, 0x09, 0x88, 
//   0x97, 0x76, 0x03, 0x41, 0x7B, 0xA9, 0x40, 0x99, 
//   0x0E, 0x06, 0x06, 0xCC, 0xBB, 0xBB, 0xBB, 0xA9, 
//   0x20, 0x74, 0x10, 0x12, 0x06, 0xEE, 0xDC, 0xA7, 
//   0x61, 0x0D, 0x10, 0xED, 0xDC, 0xCD, 0x16, 0x06, 
//   0x4F, 0xFF, 0xEE, 0xEE, 0x08, 0x74, 0xCE, 0xCA, 
//   0x76, 0x08, 0x47, 0x1E, 0xEC, 0x97, 0x0A, 0x7F, 
//   0xFF, 0xFE, 0xED, 0x1E, 0x02, 0x60, 0x1F, 0x41, 
//   0xAF, 0x00, 0xFF, 0xFD, 0xCC, 0x00, 0x0B, 0xFD, 
//   0xB9, 0x92, 0x83, 0x22, 0x45, 0x20, 0x0D, 0xFF, 
//   0xEC, 0xBF, 0x05, 0x02, 0x26, 0x41, 0x60, 0xA2, 
//   0x27, 0x41, 0x03, 0x02, 0xB6, 0xAF, 0xFF, 0xFE, 
//   0xC1, 0x80, 0x2A, 0x45, 0xCE, 0xFF, 0xFF, 0xFF, 
//   0xBF, 0xFF, 0xFE, 0xA0, 0x08, 0x03, 0xA0, 0x08, 
//   0x03, 0xFF, 0xDD, 0xDF, 0xFF, 0xFF, 0x40, 0xFC, 
//   0x20, 0x46, 0xEF, 0xCB, 0x97, 0x40, 0x7F, 0xFF, 
//   0x62, 0xFF, 0x18, 0x03, 0x20, 0x04, 0xFF, 0xFD, 
//   0xD2, 0x39, 0x49, 0xB0, 0xB0, 0x3C, 0x41, 0x0D, 
//   0x05, 0x01, 0x30, 0x07, 0xFF, 0xFF, 0xFE, 0xC2, 
//   0xA2, 0x41, 0x49, 0xC9, 0x3B, 0x02, 0x9F, 0xFF, 
//   0xFF, 0x46, 0x07, 0x1C, 0xE3, 0x17, 0x41, 0x27, 
//   0x46, 0x4B, 0x41, 0xFF, 0xCA, 0x61, 0x08, 0x43, 
//   0x4E, 0x08, 0x07, 0x04, 0xDF, 0xFF, 0xFE, 0xCA, 
//   0x48, 0x87, 0x2A, 0xC1, 0x13, 0xC2, 0x44, 0x04, 
//   0x53, 0x8B, 0x47, 0xBB, 0xB4, 0x5A, 0x14, 0x00, 
//   0x00,
// };

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv)
{
    uint8_t *decompressed = malloc(DECOMPRESSED_SIZE);
    uint8_t *recompressed;
    int recompressedSize;
    // int i;

    // printf("Original compressed:\n  ");
    // for (i = 0; i < COMPRESSED_SIZE; i++)
    // {
    //     if (i % 16 == 0 && i != 0)
    //     {
    //         printf("\n  ");
    //     }
    //     printf("%02X ", original[i]);
    // }
    // printf("\n");

    decompress(&decompressionParamsTable[0], COMPRESSED_SIZE, original, DECOMPRESSED_SIZE, decompressed);

    // printf("Decompressed:\n  ");
    // for (i = 0; i < DECOMPRESSED_SIZE; i++)
    // {
    //     if (i % 16 == 0 && i != 0)
    //     {
    //         printf("\n  ");
    //     }
    //     printf("%02X ", decompressed[i]);
    // }
    // printf("\n");

    recompressedSize = compress(&decompressionParamsTable[0], DECOMPRESSED_SIZE, decompressed, &recompressed, 0);

    // printf("Decompressed:\n  ");
    // for (i = 0; i < DECOMPRESSED_SIZE; i++)
    // {
    //     if (i % 16 == 0 && i != 0)
    //     {
    //         printf("\n  ");
    //     }
    //     printf("%02X ", decompressed[i]);
    // }
    // printf("\n");

    // printf("min size: %d\n", MIN(recompressedSize, COMPRESSED_SIZE));
    // printf("compressed size: %d\n", COMPRESSED_SIZE);
    // printf("recompressed size: %d\n", recompressedSize);
    // printf("\n");

    // printf("Recompressed:\n  ");
    // for (i = 0; i < recompressedSize; i++)
    // {
    //     if (i % 16 == 0 && i != 0)
    //     {
    //         printf("\n  ");
    //     }
    //     printf("%02X ", recompressed[i]);
    // }
    // printf("\n");

    printf("output and input match: %s\n", memcmp(recompressed, original, COMPRESSED_SIZE) ? "False" : "True");

    free(decompressed);
    free(recompressed);

    return EXIT_SUCCESS;
}
