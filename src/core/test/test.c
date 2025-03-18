#include "core.h"

int main() {
    const char *device = "/dev/sdb";
    const char *wrong_device = "/dev/iswrongdevice";
    // format_device(device);
    RESULT_STATUS status = create_mbr_partition(wrong_device);

    printf("%d\n", status); // Status 1: Could not open device.
}