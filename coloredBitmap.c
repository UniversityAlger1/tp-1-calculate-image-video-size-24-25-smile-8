#include <string.h>
#include "config/coloredBitmap.h"

// Parameters:
//   w: width of the image
//   h: height of the image
//   unit: Unit of the output value. It could be 'bt' (bits), 'ko' (kilobytes), 'mo' (megabytes), 'go' (gigabytes)
// Return value
//   Grayscale image size Bitmap (based on the unit passed parameter)
float coloredBitmap(int w, int h, char* unit) {
    // Calculate the total size in bytes (grayscale: 1 byte per pixel)
    int sizeInBytes = w * h;

    // Convert the size based on the specified unit
    if (strcmp(unit, "bt") == 0) {
        return sizeInBytes * 8; // Convert bytes to bits
    } else if (strcmp(unit, "ko") == 0) {
        return sizeInBytes / 1024.0; // Convert bytes to kilobytes
    } else if (strcmp(unit, "mo") == 0) {
        return sizeInBytes / (1024.0 * 1024.0); // Convert bytes to megabytes
    } else if (strcmp(unit, "go") == 0) {
        return sizeInBytes / (1024.0 * 1024.0 * 1024.0); // Convert bytes to gigabytes
    }

    // Default return value (if the unit is invalid)
    return 0;
}
