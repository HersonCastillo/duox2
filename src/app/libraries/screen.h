#ifndef _SCREEN_H

#define _SCREEN_H
    #define MAGIC_NUMBER 0xb8000
    #define WIDTH_SCREEN 80
    #define HEIGHT_SCREEN 25
    #define WHITE_TXT 0x07

    void clear_screen();
    void cprintf(char *message, unsigned int line);

#endif