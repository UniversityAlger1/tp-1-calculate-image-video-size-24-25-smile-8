#include <string.h>
#include "config/coloredBitmap.h"

// Parameters:
//   w: width of the image
//   h: height of the image
//   unit: Unit of the output value. It could be:
//         'bt' for bits, 'ko' for kilobits, 'mo' for megabits, 'go' for gigabits
// Return value:
//   colored image size Bitmap (based on the unit passed as a parameter)
float coloredBitmap(int w, int h, char* unit) {
   // Calculate size in bits (1 pixel = 3 bytes = 24 bits)
   float sizeInBits = (float)(w * h * 24);

   // Convert size to the desired unit
   if (strcmp(unit, "bt") == 0) {
       return sizeInBits; // Return size in bits
   } else if (strcmp(unit, "ko") == 0) {
       return sizeInBits / 1024.0; // Convert to kilobits
   } else if (strcmp(unit, "mo") == 0) {
       return sizeInBits / (1024.0 * 1024.0); // Convert to megabits
   } else if (strcmp(unit, "go") == 0) {
       return sizeInBits / (1024.0 * 1024.0 * 1024.0); // Convert to gigabits
   }

   // Default: return 0 if the unit is invalid
   return 0.0;
}

