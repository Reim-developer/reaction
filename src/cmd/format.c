#include "include/format.h"
#include "sys/include/core.h"
#include <stdio.h>

RESULT_STATUS format_cmd(int argc, char *args[]) {
    if(argc < 3 ) {
        printf("%s", MISSING_ARGS_MSG);
        return MISSING_ARGS;
    }

    const char *device_path = args[2];
    RESULT_STATUS task_status = format_device(device_path);

    if(task_status == OPEN_DEVICE_FAILED) {
        printf(OPEN_DEVICE_FAILED_MSG);
        return OPEN_DEVICE_FAILED;
    } else if(task_status == WRITE_DEVICE_FAILED) {
        printf(OPEN_DEVICE_FAILED_MSG);
        return WRITE_DEVICE_FAILED;
    } else if(task_status == SYNC_DEVICE_FAILED) {
        printf(SYNC_DEVICE_FAILED_MSG);
        return SYNC_DEVICE_FAILED;
    } 
    printf(FORMAT_SUCCESS_MSG);
    return SUCCESS;
}