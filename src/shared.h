#ifndef SHARED_H
#define SHARED_H
#include <stdio.h>

void select(FILE *f, int num_table);
void insert(FILE *f, int num_table);
void update(FILE *f, int num_table, int id_record);
int count(FILE *f, int num_table);

#endif