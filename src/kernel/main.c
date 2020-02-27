#define MAGIC_NUMBER 0xb8000
#define WIDTH_SCREEN 80
#define HEIGHT_SCREEN 25
#define WHITE_TXT 0x07

#include "../app/libraries/bootstrap.h"

void clear_screen();
void k_printf(char *message, unsigned int line);

void kernel_main() {
    bootstrap();
    clear_screen();
    k_printf("Hello World", 0);
}

void clear_screen() {
    char *videoCard = (char *) MAGIC_NUMBER;
    int index = 0u;
    int screen_size = WIDTH_SCREEN * HEIGHT_SCREEN * 2;
    while (index < screen_size) {
        videoCard[index++] = ' ';
        videoCard[index++] = WHITE_TXT;
    }
}

void k_printf(char *message, unsigned int line) {
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
