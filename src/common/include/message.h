#ifndef MESSAGE_H
#define  MESSAGE_H

#ifdef __cplusplus
extern "C" {
#endif 
#define DEVICE_NOT_FOUND "Device name or device path is missing. You can use reload button or choose device manually."
#define DEVICE_PATH_NOT_FOUND "Device is not detected. Ensure the device is properly connected and recognized by the system."
#define NO_ACCESS_PERMIT "Can't access the device with reason: No access permit. You should run the application with root permit and try again."
#define NO_WRITE_PERMIT "Can't write the device with reason: No write permit. You should run the application with root permit and try again."
#define ISO_PATH_NOT_FOUND "Image/ISO file not found or empty. Please choose valid file and try again."

#ifdef __cplusplus
}
#endif
#endif
