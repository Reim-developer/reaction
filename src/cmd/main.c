#include <stdio.h>
#include <string.h>
#include "include/cmd.h"
#include "include/macro.h"
#include "sys/include/status.h"
#include <unistd.h>

int main(int argc, char *argv[]) {
    if(argc == 1 || argv[1] == NULL) {
        printf(INVALID_USAGE_MSG);
        return INVALID_USAGE;
    } else if(strcmp(argv[1], "format") == 0) {
        format_cmd(argc, argv);
        return SUCCESS;
    }
    printf( BAD_USAGE_MSG, argv[1]);
    
    return INVALID_USAGE;
}