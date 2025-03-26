#ifndef CORE_H
#define CORE_H
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <parted/parted.h>
#include <mntent.h>
#include <sys/mount.h>
#include <errno.h>
#include "fat32.h"
#include "../common/status.h"

RESULT_STATUS unmount_device(const char *device);
RESULT_STATUS format_device(const char *device);
RESULT_STATUS create_mbr_partition(const char *device);
RESULT_STATUS create_fat32_file_system(const char *device);

#endif // CORE_H
