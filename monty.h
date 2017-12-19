#ifndef __MONTY__H
#define __MONTY__H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void open_file(char *);
void read_file(FILE *);
int len_chars(FILE *);
void interpret_line(char *);

#endif /*__MONTY__H*/
