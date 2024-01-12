#include "shared.h"

#include <stdio.h>
#include <string.h>

#include "master_levels_db.h"
#include "master_modules_db.h"
#include "master_status_events_db.h"

void select(FILE *f, int num_table) {
    int num_of_records;
    printf("Insert the number of records or leave empty to output all of them:\n");
    scanf("%d", &num_of_records);
    // modules
    if (num_table == 1) {
        int len = modules_get_records_count_in_file(f);
        if (num_of_records > len || num_of_records < 0) {
            printf("n/a");
        } else {
            for (int i = 0; i < num_of_records + 1; i++) {
                struct modules str;
                str = modules_read_record_from_file(f, i);
                printf("%d %s %d %d %d\n", str.id, str.name, str.num_level, str.num_cell, str.flag_del);
            }
        }

    }
    // levels
    else if (num_table == 2) {
        // int len = levels_get_records_count_in_file(f);
        for (int i = 0; i < num_of_records; i++) {
            struct levels str;
            str = levels_read_record_from_file(f, i);
            printf("%d %d %d\n", str.memory_level_numbers, str.num_of_cells_per_level, str.sec_flag);
        }
    }
    // status_events
    else if (num_table == 3) {
        // int len = status_events_get_records_count_in_file(f);
        for (int i = 0; i < num_of_records + 1; i++) {
            struct status_events str;
            str = status_events_read_record_from_file(f, i);
            printf("%d %d %d %s %s\n", str.id_event, str.id_module, str.new_module_status, str.date_of_change,
                   str.change_time);
        }
    }
}

void insert(FILE *f, int num_table) {
    if (num_table == 1) {
        int len = modules_get_records_count_in_file(f);
        int id = len, num_level, num_cell, flag_del;
        char name[30];
        printf("Please input the name(char[30]), num_level(int), num_cell(int), flag_del(int)\n");
        scanf("%29s", name);
        scanf("%d", &num_level);
        scanf("%d", &num_cell);
        scanf("%d", &flag_del);
        struct modules str = {.id = id, .num_level = num_level, .num_cell = num_cell, .flag_del = flag_del};
        strcpy(str.name, name);
        modules_write_record_in_file(f, &str, len);
    } else if (num_table == 2) {
        int len = levels_get_records_count_in_file(f);
        int memory_level_numbers = len, num_of_cells_per_level, sec_flag;
        printf("Please input the num_of_cells_per_level(int), sec_flag(int)\n");
        scanf("%d", &num_of_cells_per_level);
        scanf("%d", &sec_flag);
        struct levels str = {memory_level_numbers, num_of_cells_per_level, sec_flag};
        levels_write_record_in_file(f, &str, len);
    } else if (num_table == 3) {
        int len = status_events_get_records_count_in_file(f);
        int id_event = len, id_module, new_module_status;
        char date_of_change[12], change_time[10];
        printf(
            "Please input the id_module(int), new_module_status(int), date_of_change(char[11]), "
            "change_time(char[9])\n");
        scanf("%d", &id_module);
        scanf("%d", &new_module_status);
        scanf("%11s", date_of_change);
        scanf("%9s", change_time);
        struct status_events str = {
            .id_event = id_event, .id_module = id_module, .new_module_status = new_module_status};
        strcpy(str.date_of_change, date_of_change);
        strcpy(str.change_time, change_time);
        status_events_write_record_in_file(f, &str, len);
    } else
        printf("n/a");
}

void update(FILE *f, int num_table, int id_record) {
    if (num_table == 1) {
        int len = modules_get_records_count_in_file(f);
        if (id_record >= len || id_record < 0) {
            printf("n/a");
        } else {
            int num_level, num_cell, flag_del;
            char name[30];
            printf("Please input the name(char[30]), num_level(int), num_cell(int), flag_del(int)\n");
            scanf("%29s", name);
            scanf("%d", &num_level);
            scanf("%d", &num_cell);
            scanf("%d", &flag_del);
            struct modules str = {
                .id = id_record, .num_level = num_level, .num_cell = num_cell, .flag_del = flag_del};
            strcpy(str.name, name);
            modules_write_record_in_file(f, &str, id_record);
        }
    } else if (num_table == 2) {
        int len = levels_get_records_count_in_file(f);
        if (id_record > len || id_record < 0) {
            printf("n/a");
        } else {
            int memory_level_numbers = id_record, num_of_cells_per_level, sec_flag;
            printf("Please input the num_of_cells_per_level(int), sec_flag(int)\n");
            scanf("%d", &num_of_cells_per_level);
            scanf("%d", &sec_flag);
            struct levels str = {memory_level_numbers, num_of_cells_per_level, sec_flag};
            levels_write_record_in_file(f, &str, id_record - 1);
        }
    } else if (num_table == 3) {
        int len = status_events_get_records_count_in_file(f);
        if (id_record >= len || id_record < 0) {
            printf("n/a");
        } else {
            int id_event = id_record, id_module, new_module_status;
            char date_of_change[12], change_time[10];
            printf(
                "Please input the id_module(int), new_module_status(int), date_of_change(char[11]), "
                "change_time(char[9])\n");
            scanf("%d", &id_module);
            scanf("%d", &new_module_status);
            scanf("%11s", date_of_change);
            scanf("%9s", change_time);
            struct status_events str = {
                .id_event = id_event, .id_module = id_module, .new_module_status = new_module_status};
            strcpy(str.date_of_change, date_of_change);
            strcpy(str.change_time, change_time);
            status_events_write_record_in_file(f, &str, id_record);
        }
    } else
        printf("n/a");
}

int count(FILE *f, int num_table) {
    int count;
    if (num_table == 1) {
        count = modules_get_records_count_in_file(f) - 1;
    } else if (num_table == 2) {
        count = levels_get_records_count_in_file(f);
    } else if (num_table == 3) {
        count = status_events_get_records_count_in_file(f) - 1;
    } else
        printf("n/a");
    return count;
}