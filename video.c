#include <string.h>
#include "config/video.h"

// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in second of movie (colored image)
//   durationCredits: duration in second of credit (image Black/White)
//   fps: Frames Per Second (fps) of the video
//   unit: Unit of the output value. It could be 'bt' byte, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored video size (based on the unit passed parameter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
    // Calculate the size of the color section (3 bytes per pixel for colored images)
    float sizeColor = (float)(w * h * 3 * fps * durationMovie);

    // Calculate the size of the black-and-white section (1 byte per pixel for black/white images)
    float sizeBW = (float)(w * h * fps * durationCredits);

    // Total size in bytes
    float totalSize = sizeColor + sizeBW;

    // Convert size to the desired unit
    if (strcmp(unit, "bt") == 0) {
        return totalSize;  // Return size in bytes
    } else if (strcmp(unit, "ko") == 0) {
        return totalSize * 8 / 1024.0;  // Convert bytes to kilobits (1 kilobit = 1024 bits)
    } else if (strcmp(unit, "mo") == 0) {
        return totalSize * 8 / (1024.0 * 1024.0);  // Convert bytes to megabits (1 megabit = 1024 kilobits)
    } else if (strcmp(unit, "go") == 0) {
        return totalSize * 8 / (1024.0 * 1024.0 * 1024.0);  // Convert bytes to gigabits (1 gigabit = 1024 megabits)
    }

    // If the unit is not recognized, return 0
    return 0.0;
}
