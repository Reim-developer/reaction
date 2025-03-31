#include "format.h"
#include "include/context.h"
#include <stdio.h>

CONTEXT format_cmd(int argc, char *args[]) {
    if(argc < 3 ) {
        printf("%s", MISSING_ARGS_MSG);
        return MISSING_ARGS;
    }

    const char *device_path = args[2];

    return SUCCSSS;
}