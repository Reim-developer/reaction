#ifndef CONTEXT_H
#define CONTEXT_H

typedef enum {
    SUCCESS, /* With no error. Expands to 0 */
    NO_PERMIT_OPERATION, /* No permit access, write. Expands to 1 */

    GET_MOUNT_FAILED, /* Get mount point failed. Expands to 2 */
    GET_MOUNT_SUCCESS, /* Get mount point success. Expands to 3 */
    UNMOUNT_DEVICE_FAILED, /* Unmount device failed. Expands to 4 */
    UNMOUNT_DEVICE_SUCCESS, /* Unmount device success. Expands to 5 */

    OPEN_DEVICE_FAILED, /* Open device failed. Expands to 6 */
    WRITE_DEVICE_FAILED, /* Write to device failed. Expands to 7 */
    SYNC_DEVICE_FAILED, /* Sync device failed. Expands to  8 */

    DEVICE_NOT_FOUND, /* Device not found. Expands to 9 */

    ADD_PARTITION_FAILED, /* Add partition to device failed. Expands to 10 */
    COMMIT_PARTITION_FAILED, /* Commit to partition device failed. Expands to 11 */
    LOAD_DISK_INFO_FAILED, /* Load disk info is failed. Expands to 12 */
    PARTITION_NOT_FOUND,  /* Partition not found. Expands to 13 */
    GET_GEOMETRY_PARTITION_FAILED, /* Get geometry partition of device failed. Expands to  14*/
    
    FORMAT_FAT32_FAILED, /* Format device with FAT32 file  system failed. Expands to  15 */

    PARTITION_TOO_BIG, /* Partition too big. Expands to 16 */
    PARTITION_TOO_SMALL, /* Partition too small. Expands to 17 */
    MAX_CLUSTER_ERROR, /* Max cluster error. Expands to 18 */

    WRITE_BOOT_SECTOR_FAILED, /* Write boot sector failed. Expands to 19 */
    WRITE_FS_INFO_FAILED, /* Write FS info failed. Expands to 20 */
    WRITE_SECTOR_FAILED /* Write sector in device failed. Expands to 21 */
} RESULT_STATUS;

#endif // CONTEXT_h
