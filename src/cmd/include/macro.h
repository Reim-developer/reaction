#ifndef MACRO_H
#define MACRO_H

#define NO_PERMIT_MSG "No permit operation. Are you run this command with root permit?\n"

#define INVALID_USAGE_MSG "Invalid usage. Try helper --help for more infomation\n"
#define BAD_USAGE_MSG "Bad usage: %s\nUse helper --help for more infomation.\n"

#define MISSING_ARGS_MSG "Missing argument: device_path\n"
#define OPEN_DEVICE_FAILED_MSG "Open device failed. Maybe device not found.\n"

#define WRITE_DEVICE_FAILED_MSG "Write to device failed. Run with root permit and try again.\n"
#define SYNC_DEVICE_FAILED_MSG "Sync device failed. Please try again.\n"

#define FORMAT_SUCCESS_MSG "Format device successfully.\n"
#define DEVICE_NOT_FOUND_MSG "This device not found.\n"

#define UMOUNT_DEVICE_FAILED_MSG "Unmount the device failed.\n"
#define ADD_PARTITION_FAILED_MSG "Add partition for the disk failed.\n"

#define COMMIT_PARTITION_FAILED_MSG "Commit partition for the disk failed.\n"

#endif // MACRO_H
