#ifndef slideline_h_
#define slideline_h_
#define SLIDE_LEFT 1
#define SLIDE_RIGHT 0
#include <stdlib.h>

int slide_line(int *line, size_t size, int direction);
void print_array1(int const *array, size_t size);
void left_array1(int *array, int *line, size_t size);
void right_array1(int *array, int *line, size_t size);
#endif
