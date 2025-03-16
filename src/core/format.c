#include "format.h"


void format_device(const char *device) {
   int fd_status = open(device, O_RDWR | O_EXCL);

   if(fd_status < 0) {
        printf("Could not open device %s\n", device);
        return;
   }
   char zero_buffer[512];

   memset(zero_buffer, 0, sizeof(zero_buffer));
   if(write(fd_status, zero_buffer, sizeof(zero_buffer)) != sizeof(zero_buffer)) {
        printf("Write failed\n");
        close(fd_status);
        return;
   }

   printf("Write successfully\n");
   close(fd_status);
}