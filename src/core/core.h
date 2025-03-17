#ifndef FORMAT_H
#define FORMAT_H
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <parted/parted.h>

void format_device(const char *device);
void create_mbr_partition(const char *device);

#endif