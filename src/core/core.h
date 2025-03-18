#ifndef FORMAT_H
#define FORMAT_H
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <parted/parted.h>

typedef enum {
    SUCCESS = 0,
    DEVICE_NOT_FOUND = 1,
    ADD_PARTITION_FAILED = 2,
    COMMIT_PARTITION_FAILED = 3,
    WRITE_FAILED = 4,
    OPEN_DEVICE_FAILED = 5,
    FILE_SYNC_FAILED = 6
} RESULT_STATUS;

RESULT_STATUS format_device(const char *device);
RESULT_STATUS create_mbr_partition(const char *device);

#endif