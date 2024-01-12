#ifndef MASTER_LEVELS_DB_H
#define MASTER_LEVELS_DB_H

#include <stdio.h>
/*
Таблица уровней ("LEVELS") состоит из:
    Номера уровня памяти (int);
    Кол-ва ячеек на уровне (int);
    Флаг защищенности (int).
*/

struct levels {
    int memory_level_numbers;
    int num_of_cells_per_level;
    int sec_flag;
};

struct levels levels_read_record_from_file(FILE *pfile, int index);
void levels_write_record_in_file(FILE *pfile, const struct levels *record_to_write, int index);
int levels_get_file_size_in_bytes(FILE *pfile);
int levels_get_records_count_in_file(FILE *pfile);

#endif
