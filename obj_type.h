#pragma once
#include <stddef.h>
#include "obj_var.h"


typedef struct obj_type_t        obj_type_t;


struct object_type_t {

    OBJ_VAR_HEAD

    char*           name;
    size_t          basic_size;
    size_t          item_size;
    size_t          flags;
    char*           documentation;
    obj_type_t*     base_type;

};



obj_type_t*     obj_type__new();

void            obj_type__print(obj_type_t* self);



void            obj_type__kill(obj_type_t** self_p);

































































