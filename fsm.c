#include "fsm.h"
#include <stdlib.h>
#include <string.h>


fsm_t* fsm__new() {

    fsm_t* self = malloc(sizeof(fsm_t));
    memset(self, 0, sizeof(fsm_t));

    return self;

}

int fsm__run(fsm_t* self) {

    while (!fsm__execute_next_state(self))
        ;

    return 0;

}


int fsm__execute_next_state(fsm_t* self) {

    state_t* tmp = self->start_state;
    if ((self->start_state == NULL) || (self->current_state == NULL))
        return -1;
    while ((tmp->name != self->current_state_name) && (tmp != NULL))
        tmp = tmp->next;
    if (tmp == NULL)
        return -1;
    tmp->callback(self, self->current_state_num, self->arg_values);

    return 0;

}

int fsm__add_state(fsm_t* self, char* state_name, callback_f callback) {

    state_t* tmp = self->start_state;
    state_t* new_state = malloc(sizeof(state_t));
    while (tmp->next)
        tmp = tmp->next;
    new_state->name = state_name;
    new_state->callback = callback;
    new_state->next = NULL;
    tmp->next = new_state;

    return 0;

}

int fsm__add_default_state(fsm_t* self, callback_f callback) {

    self->start_state = malloc(sizeof(state_t));
    self->start_state->name = strdup("default");
    self->start_state->callback = callback;
    self->start_state->next = NULL;
    self->current_state = self->start_state;
    self->current_state_name = self->start_state->name;

    return 0;

}

int fsm__remove_state(fsm_t* self, char* state_name) {

    if (!strcmp(state_name, "default"))
        return -1;
    state_t* to_del;
    state_t* tmp = self->start_state;
    while ((tmp->next != NULL) && (strcmp(tmp->next->name, state)))
        tmp = tmp->next;
    if (tmp == NULL)
        return -1;
    to_del = tmp->next;
    tmp->next = tmp->next->next;
    free(to_del->name);
    free(to_del);

    return 0;

}

int fsm__change_state(fsm_t* self, char* state_name, int num, void** arg_values) {

    state_t* tmp = self->start_state;
    while ((tmp != NULL) && (strcmp(tmp->name, state)))
        tmp = tmp->next;
    if (tmp == NULL)
        return -1;
    self->current_state = tmp;
    self->current_state_name = tmp->name;
    self->current_state_num = num;
    self->arg_values = arg_values;

}

void fsm__kill(fsm_t** self_p);



















































































