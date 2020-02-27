#include "../libraries/screen.h"

void clear_screen() {
    char *videoCard = (char *) MAGIC_NUMBER;
    int index = 0u;
    int screen_size = WIDTH_SCREEN * HEIGHT_SCREEN * 2;
    while (index < screen_size) {
        videoCard[index++] = ' ';
        videoCard[index++] = WHITE_TXT;
    }
}

void cprintf(char *message, unsigned int line) {
    char *videoCard = (char *) MAGIC_NUMBER;
    int index = 0u;
    index = line * WIDTH_SCREEN * 2;
    while (*message != 0) {
        if (*message == '\n') {
            index = (++line) * WIDTH_SCREEN * 2;
            *message++;
        } else {
            videoCard[index++] = *message;
            *message++;
            videoCard[index++] = WHITE_TXT;
        }
    }
}