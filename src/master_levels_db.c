#include "master_levels_db.h"

#include <stdio.h>

// Function of reading a record of a given type from a file by its serial number.
struct levels levels_read_record_from_file(FILE *pfile, int index) {
    // Calculation of the offset at which desired entry should be located from the beginning of the file.
    int offset = index * sizeof(struct levels);
    // Move the position pointer to the calculated offset from the beginning of the file.
    fseek(pfile, offset, SEEK_SET);

    // Reading a record of the specified type from a file.
    struct levels record;
    fread(&record, sizeof(struct levels), 1, pfile);

    // For safety reasons, we return the file position pointer to the beginning of the file.
    rewind(pfile);

    // Return read record
    return record;
}

// Function of writing a record of the specified type to the file at the specified serial number.
void levels_write_record_in_file(FILE *pfile, const struct levels *record_to_write, int index) {
    // Calculation of the offset at which the required record should be located from the beginning of the
    // file.
    int offset = index * sizeof(struct levels);
    // Move the position pointer to the calculated offset from the beginning of the file.
    fseek(pfile, offset, SEEK_SET);

    // Write a record of the specified type to a file.
    fwrite(record_to_write, sizeof(struct levels), 1, pfile);

    // Just in case, force the I/O subsystem to write the contents of its buffer to a file right now.
    fflush(pfile);

    // For safety reasons, return the file position pointer to the beginning of the file.
    rewind(pfile);
}

// Function to get file size in bytes.
int levels_get_file_size_in_bytes(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);  // Move the position pointer to the end of the file.
    size = ftell(
        pfile);  // Read the number of bytes from the beginning of the file to the current position pointer.
    rewind(pfile);  // For safety reasons, move the position pointer back to the beginning of the file.
    return size;
}

// Function to get count of records in file
int levels_get_records_count_in_file(FILE *pfile) {
    return levels_get_file_size_in_bytes(pfile) / sizeof(struct levels);
}
