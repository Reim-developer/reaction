#include "core.h"

RESULT_STATUS format_device(const char *device) {
   int fd_status = open(device, O_RDWR | O_EXCL);

   if(fd_status < 0) 
     return OPEN_DEVICE_FAILED;

   char zero_buffer[512] = {0};
   if(write(fd_status, zero_buffer, sizeof(zero_buffer)) != sizeof(zero_buffer)) {
        close(fd_status);
        return WRITE_FAILED;
   }

   if(fsync(fd_status) < 0) {
     close(fd_status);
     return FILE_SYNC_FAILED;
   }

   close(fd_status);
   return SUCCESS;
}

RESULT_STATUS create_mbr_partition(const char *device) {
     PedDevice *device_t = ped_device_get(device);
     if(!device_t) {
          printf("Could not open %s\n", device);
          return DEVICE_NOT_FOUND;
     }

     PedDiskType *disk_type_t = ped_disk_type_get("msdos");
     PedDisk *disk_t = ped_disk_new_fresh(device_t, disk_type_t);

     if(!disk_t) 
          return ADD_PARTITION_FAILED;
     
     PedSector sector_start_t = 1;
     PedSector sector_end_t = device_t->length - 1;
     PedPartition *ped_partition_t = ped_partition_new(disk_t, PED_PARTITION_NORMAL, NULL, sector_start_t, sector_end_t);

     if(!ped_partition_t) {
          ped_disk_destroy(disk_t);
          return ADD_PARTITION_FAILED;
     }

     if(!ped_disk_add_partition(disk_t, ped_partition_t, ped_constraint_any(device_t))) {
          ped_disk_destroy(disk_t);
          return ADD_PARTITION_FAILED;
     }

     if(!ped_disk_commit_to_dev(disk_t) || !ped_disk_commit(disk_t)) {
          ped_disk_destroy(disk_t);
          ped_device_destroy(device_t);
          return COMMIT_PARTITION_FAILED;
     }

     ped_disk_destroy(disk_t);
     ped_device_destroy(device_t);

     return SUCCESS;
}