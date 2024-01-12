#include "master_status_events_db.h"

#include <stdio.h>

// Function of reading a record of a given type from a file by its serial number.
struct status_events status_events_read_record_from_file(FILE *pfile, int index) {
    int offset = index * sizeof(struct status_events);
    fseek(pfile, offset, SEEK_SET);

    struct status_events record;
    fread(&record, sizeof(struct status_events), 1, pfile);

    rewind(pfile);
    return record;
}

// Function of writing a record of the specified type to the file at the specified serial number.
void status_events_write_record_in_file(FILE *pfile, const struct status_events *record_to_write, int index) {
    int offset = index * sizeof(struct status_events);
    fseek(pfile, offset, SEEK_SET);

    fwrite(record_to_write, sizeof(struct status_events), 1, pfile);

    fflush(pfile);
    rewind(pfile);
}

int status_events_get_file_size_in_bytes(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);  // Move the position pointer to the end of the file.
    size = ftell(
        pfile);  // Read the number of bytes from the beginning of the file to the current position pointer.
    rewind(pfile);  // For safety reasons, move the position pointer back to the beginning of the file.
    return size;
}

int status_events_get_records_count_in_file(FILE *pfile) {
    return status_events_get_file_size_in_bytes(pfile) / sizeof(struct status_events);
}
