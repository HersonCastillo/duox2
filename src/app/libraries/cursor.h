#ifndef _CURSOR_H

#define _CURSOR_H

  #include "definitions.h"

  void clear_screen();
  void update_cursor();
  void new_line_check();
  void print(string message);
  void print_char(char character);
  void scroll_up(unsigned short lineNumber);
  void clear_line(unsigned short from, unsigned short to);

#endif