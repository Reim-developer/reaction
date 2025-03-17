#include "core.h"

int main() {
    const char *device = "/dev/sdb";
    // format_device(device);
    create_mbr_partition(device);
}