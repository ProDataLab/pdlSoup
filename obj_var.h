#pragma once

#include <stddef.h>
#include "obj.h"


typedef struct obj_var_t     obj_var_t;


struct obj_var_t {

    obj_t       base;
    size_t      size;

};



#define OBJ_VAR_HEAD obj_var_t base;
