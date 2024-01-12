#ifndef MASTER_MODULES_DB_H
#define MASTER_MODULES_DB_H

#include <stdio.h>

struct modules {
    int id;
    char name[30];
    int num_level;
    int num_cell;
    int flag_del;
};

struct modules modules_read_record_from_file(FILE *pfile, int index);
void modules_write_record_in_file(FILE *pfile, const struct modules *record_to_write, int index);
// void modules_swap_records_in_file(FILE *pfile, int record_index1, int record_index2);
int modules_get_file_size_in_bytes(FILE *pfile);
int modules_get_records_count_in_file(FILE *pfile);

#endif