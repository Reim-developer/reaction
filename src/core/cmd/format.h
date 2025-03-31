#ifndef FORMAT_H
#define FORMAT_H
#include "include/context.h"
#define MISSING_ARGS_MSG "Missing argument: device_path\nUsage: helper format <DEVICE_PATH>"

CONTEXT format_cmd(int argv, char *args[]);

#endif // FORMAT_H

