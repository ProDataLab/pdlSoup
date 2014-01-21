#pragma once
#include <stddef.h>
#include "object_type.h"


typedef struct obj_t        obj_t;
typedef unsigned int        uint_t;


struct obj_t {

    uint_t  reference_count;
    obj_type_t  type;

};


obj_t* obj__new(obj_type_t* obj_type);





























































