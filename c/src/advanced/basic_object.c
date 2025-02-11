#include "basic_object.h"

static void increment(Counter *self) { self->value++; }
static void print(Counter *self) {    printf("Counter value: %d\n", self->value); }

static void delete_counter(Counter *c) { free(c); }
static Counter *new_counter(int initial_value) {
    Counter *c = (Counter *)malloc(sizeof(Counter));
    c->value = initial_value;
    c->increment = increment;
    c->print = print;
    return c;
}

void metaobject() {
    Counter *c = new_counter(0);
    c->print(c);
    c->increment(c);
    c->print(c);
    delete_counter(c);
}
