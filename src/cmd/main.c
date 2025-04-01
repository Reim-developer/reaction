#include <stdio.h>
#include <string.h>
#include "include/format.h"
#include "sys/include/status.h"
#include <unistd.h>

int main(int argc, char *argv[]) {
    if(argc == 1 || argv[1] == NULL) {
        printf("Invalid usage\n");
        return INVALID_USAGE;
    } else if(strcmp(argv[1], "format") == 0) {
        format_cmd(argc, argv);
        return SUCCESS;
    }
    printf("Bad usage. Usage helper --help for more infomation.\n");

    
    return INVALID_USAGE;
}