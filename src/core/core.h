#ifndef CORE_H
#define CORE_H
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <parted/parted.h>
#include <mntent.h>
#include <sys/mount.h>
#include <errno.h>

typedef enum {
    SUCCESS = 0,
    DEVICE_NOT_FOUND = 1,
    ADD_PARTITION_FAILED = 2,
    COMMIT_PARTITION_FAILED = 3,
    WRITE_FAILED = 4,
    OPEN_DEVICE_FAILED = 5,
    FILE_SYNC_FAILED = 6,
    MOUNT_POINT_FOUND = 7,
    MOUNT_POINT_NOT_FOUND = 8,
    GET_MOUNT_ERROR = 9,
    UNMOUNT_DEVICE_SUCCESS = 10,
    UNMOUNT_DEVICE_FAILED =  11,
    NO_PERMIT_OPERATION = 12
} RESULT_STATUS;

RESULT_STATUS unmount_device(const char *device);
RESULT_STATUS format_device(const char *device);
RESULT_STATUS create_mbr_partition(const char *device);

#endif // CORE_H