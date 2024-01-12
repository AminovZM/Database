#include <stdio.h>

#include "logger.h"
#include "shared.h"

void select_menu();
void insert_menu();
void update_menu();
void count_menu();

int main() {
    int command;
    printf("vvedite komandu:\n   1. SELECT\n   2. INSERT\n   3. UPDATE\n   4. COUNT\n");
    scanf("%d", &command);
    if (command == 1)
        select_menu();
    else if (command == 2)
        insert_menu();
    else if (command == 3)
        update_menu();
    else if (command == 4)
        count_menu();
    else
        printf("n/a");

    return 0;
}

void select_menu() {
    int num_table;
    printf("Please choose a table:\n   1. Modules\n   2. Levels\n   3. Status events\n");
    scanf("%d", &num_table);
    FILE *f;

    FILE *file = log_init("file.log");

    if (num_table == 1) {
        logcat(file, "opened file master_modules.db for selection");
        f = fopen("../materials/master_modules.db", "r");
        select(f, num_table);
    } else if (num_table == 2) {
        logcat(file, "opened file master_levels.db for selection");
        f = fopen("../materials/master_levels.db", "r");
        select(f, num_table);
    } else if (num_table == 3) {
        logcat(file, "opened file master_status_events.db for selection");
        f = fopen("../materials/master_status_events.db", "r");
        select(f, num_table);
    } else
        printf("n/a");
    logcat(file, "file closed");
    log_close(file);
    fclose(f);
}
void insert_menu() {
    int num_table;
    printf("Please choose a table to insert:\n   1. Modules\n   2. Levels\n   3. Status events\n");
    scanf("%d", &num_table);
    FILE *f;
    FILE *file = log_init("file.log");
    if (num_table == 1) {
        logcat(file, "opened the file master_modules.db to add");
        f = fopen("../materials/master_modules.db", "r+");
        insert(f, num_table);
    } else if (num_table == 2) {
        logcat(file, "opened the file master_levels.db to add");
        f = fopen("../materials/master_levels.db", "r+");
        insert(f, num_table);
    } else if (num_table == 3) {
        logcat(file, "opened the master_status_events.db to add");
        f = fopen("../materials/master_status_events.db", "r+");
        insert(f, num_table);
    } else
        printf("n/a");
    logcat(file, "file closed");
    log_close(file);
    fclose(f);
}

void update_menu() {
    int num_table;
    int id_record;
    printf("Please choose a table to update:\n   1. Modules\n   2. Levels\n   3. Status events\n");
    scanf("%d", &num_table);
    printf("Please input id record:\n");
    scanf("%d", &id_record);
    FILE *f;
    FILE *file = log_init("file.log");
    if (num_table == 1) {
        logcat(file, "opened the master_modules.db for update");
        f = fopen("../materials/master_modules.db", "r+");
        update(f, num_table, id_record);
    } else if (num_table == 2) {
        logcat(file, "opened the master_levels.d for update");
        f = fopen("../materials/master_levels.db", "r+");
        update(f, num_table, id_record);
    } else if (num_table == 3) {
        logcat(file, "opened the master_status_events.db for update");
        f = fopen("../materials/master_status_events.db", "r+");
        update(f, num_table, id_record);
    } else
        printf("n/a");
    logcat(file, "file closed");
    log_close(file);
    fclose(f);
}

void count_menu() {
    int num_table;
    printf("Please choose a table to insert:\n   1. Modules\n   2. Levels\n   3. Status events\n");
    scanf("%d", &num_table);
    FILE *f;
    if (num_table == 1) {
        f = fopen("../materials/master_modules.db", "r");
        printf("%d", count(f, num_table));
    } else if (num_table == 2) {
        f = fopen("../materials/master_levels.db", "r");
        printf("%d", count(f, num_table));
    } else if (num_table == 3) {
        f = fopen("../materials/master_status_events.db", "r");
        printf("%d", count(f, num_table));
    } else
        printf("n/a");

    fclose(f);
}