#ifndef ARRAY_H
#define ARRAY_H


struct my_array{
    int size;
    double *data;

};

typedef struct my_array Array;


//New
void output_array(Array *a);

void shift_array(Array *a);

Array *average_adjacent(Array *a);

#endif
