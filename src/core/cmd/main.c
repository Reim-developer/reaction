#include <stdio.h>
#include "include/context.h"
#include <unistd.h>

int main(int argc, char *argv[]) {
    if(argc == 1 || argv[1] == NULL) {
        printf("Invalid usage\n");
        return INVALID_USAGE;
    }
    printf("Ok\n");

    
    return SUCCSSS;
}