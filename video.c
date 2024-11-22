#include <string.h>
#include "config/video.h"

// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in seconds of the movie (colored section)
//   durationCredits: duration in seconds of the credits (black-and-white section)
//   fps: Frames Per Second (fps) of the video
//   unit: Unit of the output value. Could be 'bt', 'ko', 'mo', or 'go'.
// Return value:
//   Total video size in the specified unit.
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
    // Calculate size of the colored section (3 bytes per pixel)
    float sizeColor = (float)(w * h * 3 * fps * durationMovie);

    // Calculate size of the black-and-white section (1 byte per pixel)
    float sizeBW = (float)(w * h * fps * durationCredits);

    // Total size in bytes
    float totalSizeInBytes = sizeColor + sizeBW;

    // Convert size to the desired unit
    if (strcmp(unit, "bt") == 0) {
        return totalSizeInBytes; // Return size in bytes
    } else if (strcmp(unit, "ko") == 0) {
        return totalSizeInBytes * 8 / 1024.0; // Convert bytes to kilobits
    } else if (strcmp(unit, "mo") == 0) {
        return totalSizeInBytes * 8 / (1024.0 * 1024.0); // Convert bytes to megabits
    } else if (strcmp(unit, "go") == 0) {
        return totalSizeInBytes * 8 / (1024.0 * 1024.0 * 1024.0); // Convert bytes to gigabits
    }

    // If the unit is invalid, return 0
    return 0.0;
}
