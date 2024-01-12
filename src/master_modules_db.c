/*
Основная таблица модулей ("MODULES") состоит из:
    Id модуля (int);
    Название модуля (char[30]);
    Номер уровня памяти,  где находится модуль (int);
    Номер ячейки, где находится модуль на данном уровне (int);
    Флаг удаления (int).

*/
#include "master_modules_db.h"

#include <stdio.h>

// Function of reading a record of a given type from a file by its serial number.
struct modules modules_read_record_from_file(FILE *pfile, int index) {
    int offset = index * sizeof(struct modules);
    fseek(pfile, offset, SEEK_SET);

    struct modules record;
    fread(&record, sizeof(struct modules), 1, pfile);

    rewind(pfile);
    return record;
}

// Function of writing a record of the specified type to the file at the specified serial number.
void modules_write_record_in_file(FILE *pfile, const struct modules *record_to_write, int index) {
    int offset = index * sizeof(struct modules);
    fseek(pfile, offset, SEEK_SET);

    fwrite(record_to_write, sizeof(struct modules), 1, pfile);

    fflush(pfile);
    rewind(pfile);
}
/*
void modules_swap_records_in_file(FILE *pfile, int record_index1, int record_index2) {
    struct modules record1 = modules_read_record_from_file(pfile, record_index1);
    struct modules record2 = modules_read_record_from_file(pfile, record_index2);

    modules_write_record_in_file(pfile, &record1, record_index2);
    modules_write_record_in_file(pfile, &record2, record_index1);
}
*/

int modules_get_file_size_in_bytes(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);  // Move the position pointer to the end of the file.
    size = ftell(
        pfile);  // Read the number of bytes from the beginning of the file to the current position pointer.
    rewind(pfile);  // For safety reasons, move the position pointer back to the beginning of the file.
    return size;
}

int modules_get_records_count_in_file(FILE *pfile) {
    return modules_get_file_size_in_bytes(pfile) / sizeof(struct modules);
}
