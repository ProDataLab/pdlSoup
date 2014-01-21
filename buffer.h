#pragma once

#include <sys/types.h>
#include <stdbool.h>


typedef struct buffer_t     buffer_t;
typedef buffer_t            buf_t;
typedef unsigned int        uint_t;


struct buffer_t {

    size_t      size;
    size_t      item_size;
    char*       address;
    char*       format;
    bool        is_contiguous;
    bool        is_scalar;

    size_t      num_dimensions;
    size_t*     shape;
    size_t*     strides;
    ssize_t*    suboffsets;

};

// python object.h file
#define BUF_MAX_DIMENSIONS      64
#define BUF_SIMPLE              0
#define BUF_WRITABLE            0x0001
#define BUF_FORMAT              0x0004
#define BUF_NUM_DIMENSIONS      0x0008
#define BUF_STRIDES             (0x0010 | BUF_NUM_DIMENSIONS)
#define BUF_CONTIGUOUS          (0x0020 | BUF_STRIDES)
#define BUF_INDIRECT            (0x0100 | BUF_STRIDES)
#define BUF_CONTIG              (BUF_NUM_DIMENSIONS | BUF_WRITABLE)
#define BUF_CONTIG_READ_ONLY    (BUF_NUM_DIMENSIONS)
#define BUF_STRIDED             (BUF_STRIDES | BUF_WRITABLE)
#define BUF_STRIDED_READ_ONLY   (BUF_STRIDES)
#define BUF_RECORDS             (BUF_STRIDES | BUF_WRITABLE | BUF_FORMAT)
#define BUF_RECORDS_READ_ONLY   (BUF_STRIDES | BUF_FORMAT)
#define BUF_FULL                (BUF_INDIRECT | BUF_WRITABLE | BUF_FORMAT)
#define BUF_FULL_READ_ONLY      (BUF_INDIRECT | BUF_FORMAT)
#define BUF_READ                0x100
#define BUF_WRITE               0x200



buf_t* buf__new();

int buf__verify_structure(buf_t* self, size_t memory_length,
                          size_t item_size, size_t num_dimensions,
                          size_t* shape, size_t* strides,
                          size_t** offsets);

void buf__kill(buf_t** self_p);











































































