#include "core.h"

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

void create_mbr_partition(const char *device) {
     PedDevice *device_t = ped_device_get(device);
     if(!device_t) {
          printf("Could not open %s\n", device);
          return;
     }

     PedDiskType *disk_type_t = ped_disk_type_get("msdos");
     PedDisk *disk_t = ped_disk_new_fresh(device_t, disk_type_t);

     PedSector sector_start_t = 1;
     PedSector sector_end_t = device_t->length - 1;
     PedPartition *ped_partition_t = ped_partition_new(disk_t, PED_PARTITION_NORMAL, NULL, sector_start_t, sector_end_t);

     ped_disk_add_partition(disk_t, ped_partition_t, ped_constraint_any(device_t));
     ped_disk_commit_to_dev(disk_t);
     ped_disk_commit(disk_t);

     ped_disk_destroy(disk_t);
     ped_device_destroy(device_t);
}