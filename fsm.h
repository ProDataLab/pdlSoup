#pragma once


typedef struct fsm_t fsm_t;

typedef struct state_t state_t;


typedef void (*callback_f)(fsm_t* fsm, int num, void** args);


struct state_t {

    char*           name;
    callback_f      callback;
    state_t*        next;

};


struct fsm_t {

    state_t*        start_state;
    state_t*        current_state;
    char*           current_state_name;
    int             current_state_num;
    void**          arg_values;

};


fsm_t* fsm__new();

int fsm__run(fsm_t* self);

int fsm__execute_next_state(fsm_t* self);

int fsm__add_state(fsm_t* self, char* state_name, callback_f callback);

int fsm__add_default_state(fsm_t* self, callback_f callback);

int fsm__remove_state(fsm_t* self, char* state_name);

int fsm__change_state(fsm_t* self, char* state_name, int num, void** arg_values);

void fsm__kill(fsm_t** self_p);






































