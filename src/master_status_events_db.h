#ifndef MASTER_STATUS_EVENTS_DB_H
#define MASTER_STATUS_EVENTS_DB_H

#include <stdio.h>

struct status_events {
    int id_event;
    int id_module;
    int new_module_status;
    char date_of_change[11];
    char change_time[9];
};

struct status_events status_events_read_record_from_file(FILE *pfile, int index);
void status_events_write_record_in_file(FILE *pfile, const struct status_events *record_to_write, int index);
int status_events_get_file_size_in_bytes(FILE *pfile);
int status_events_get_records_count_in_file(FILE *pfile);

#endif
