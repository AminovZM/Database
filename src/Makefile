CC = gcc
CFLAGS = -Wall -Werror -Wextra

EXECUTABLE1 = ../build/database

all: build_db

build_db:
	$(CC) $(CFLAGS) -o $(EXECUTABLE1) modules_db.c shared.c master_modules_db.c master_levels_db.c master_status_events_db.c logger.c

rebuild: clean all

clean:
	rm -f $(EXECUTABLE1)