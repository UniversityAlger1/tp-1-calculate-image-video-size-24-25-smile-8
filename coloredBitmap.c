#include <string.h>
#include "config/coloredBitmap.h"

// Parameters:
//   w: width of the image
//   h: height of the image
//   unit: Unit of the output value. It could be:
//         'bt' for bits, 'ko' for kilobits, 'mo' for megabits, 'go' for gigabits
// Return value:
//   Colored image size in the specified unit.
float coloredBitmap(int w, int h, char* unit) {
    // Calculate size in bytes (1 pixel = 3 bytes)
    float sizeInBytes = (float)(w * h * 3);

    // Convert size based on the unit
    if (strcmp(unit, "bt") == 0) {
        return sizeInBytes * 8; // Convert to bits
    } else if (strcmp(unit, "ko") == 0) {
        return sizeInBytes * 8 / 1024.0; // Convert to kilobits
    } else if (strcmp(unit, "mo") == 0) {
        return sizeInBytes * 8 / (1024.0 * 1024.0); // Convert to megabits
    } else if (strcmp(unit, "go") == 0) {
        return sizeInBytes * 8 / (1024.0 * 1024.0 * 1024.0); // Convert to gigabits
    }

    // Default: return 0 if the unit is invalid
    return 0.0;
}

