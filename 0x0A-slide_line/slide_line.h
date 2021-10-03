#ifndef SLIDE_LINE_H_
#define SLIDE_LINE_H_

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

int slide_line(int *line, size_t size, int direction);
void addition(int *line, size_t size);
void alignement(int *line, size_t size);
void reverse(int *line, size_t size);

#endif /* SLIDE_LINE_H_ */
