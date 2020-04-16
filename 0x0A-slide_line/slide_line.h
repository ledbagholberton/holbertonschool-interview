#ifndef slideline_h_
#define slideline_h_
#define SLIDE_RIGHT 1
#define SLIDE_LEFT 0
#include <stdio.h>

int slide_line(int *line, size_t size, int direction);
void left_array1(int *array1, int *line, size_t size);
void right_array1(int *array1, int *line, size_t size);
#endif
