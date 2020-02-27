#ifndef _CURSOR_H

#define _CURSOR_H

    void clear_screen();
    void update_cursor();
    void new_line_check();
    void print(unsigned char *message);
    void print_char(char character);
    void scroll_up(unsigned short lineNumber);
    unsigned short strlength(unsigned char *message);
    void clear_line(unsigned short from, unsigned short to);

#endif