#ifndef FORMAT_H
#define FORMAT_H
#include "../sys/include/status.h"
#define MISSING_ARGS_MSG "Missing argument: device_path\nUsage: helper format <DEVICE_PATH>\n"
#define OPEN_DEVICE_FAILED_MSG "Open device failed. Run with root permit and try again.\n"
#define WRITE_DEVICE_FAILED_MSG "Write to device failed. Run with root permit and try again.\n"
#define SYNC_DEVICE_FAILED_MSG "Sync device failed. Please try again.\n"
#define FORMAT_SUCCESS_MSG "Format device successfully.\n"

RESULT_STATUS format_cmd(int argv, char *args[]);

#endif // FORMAT_H

