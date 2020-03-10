#include "../libraries/screen.h"
#include "../libraries/cursor.h"
#include "../libraries/assembly.h"
#include "../libraries/string.h"

struct PointersStruct {
  int cursorX;
  int cursorY;
} pointers_struct = {
  .cursorX = 0,
  .cursorY = 0
};

void clear_screen() {
  clear_line(0, HEIGHT_SCREEN - 1);
  pointers_struct.cursorX = 0;
  pointers_struct.cursorY = 0;
  update_cursor();
}

void update_cursor() {
  unsigned temp;
  temp = pointers_struct.cursorY * WIDTH_SCREEN + pointers_struct.cursorX;                                                   
  outportb(0x3D4, 14);                                                      
  outportb(0x3D5, temp >> 8);                                                       
  outportb(0x3D4, 15);
  outportb(0x3D5, temp);
}

void new_line_check() {
  if (pointers_struct.cursorY >= HEIGHT_SCREEN - 1) {
    scroll_up(1);
  }
}

void scroll_up(ushort lineNumber) {
  string vidmem = (string) MAGIC_NUMBER;
  ushort index = 0;
  clear_line(0, lineNumber - 1);                                            
  for (index; index < WIDTH_SCREEN * (HEIGHT_SCREEN - 1) * 2; index++) {
    vidmem[index] = vidmem[index + WIDTH_SCREEN * 2 * lineNumber];
  }
  clear_line(HEIGHT_SCREEN - 1 - lineNumber, HEIGHT_SCREEN - 1);
  if((pointers_struct.cursorY - lineNumber) < 0 ) {
    pointers_struct.cursorY = 0;
    pointers_struct.cursorX = 0;
  } else {
    pointers_struct.cursorY -= lineNumber;
  }
  update_cursor();
}

void clear_line(ushort from, ushort to) {
  ushort index = WIDTH_SCREEN * from * LINE_SEPARATION;
  string vidmem = (string) MAGIC_NUMBER;
  for (index; index < (WIDTH_SCREEN * to * LINE_SEPARATION); index++) {
    vidmem[index] = 0x0;
  }
}

void print(string message){
  ushort index = 0;
  _string length = strlength(message) - 1;              
  for (index; index < length; index++) {
    print_char(message[index]);
  }
}

void print_char(char character){
  string vidmem = (string) MAGIC_NUMBER;     
  switch (character) {
    case 0x08:
      if (pointers_struct.cursorX > 0) {
	      pointers_struct.cursorX--;									
        vidmem[(pointers_struct.cursorY * WIDTH_SCREEN + pointers_struct.cursorX) * LINE_SEPARATION] = 0x00;	                              
	    }
	  break;
    case '\r':
      pointers_struct.cursorX = 0;
    break;
    case '\n':
      pointers_struct.cursorX = 0;
      pointers_struct.cursorY++;
    break;
    default:
      vidmem[(pointers_struct.cursorY * WIDTH_SCREEN + pointers_struct.cursorX) * LINE_SEPARATION] = character;
      vidmem[(pointers_struct.cursorY * WIDTH_SCREEN + pointers_struct.cursorX) * LINE_SEPARATION + 1] = 0x07;
      pointers_struct.cursorX++; 
    break;
  }
  if (pointers_struct.cursorX >= WIDTH_SCREEN) {
    pointers_struct.cursorX = 0;                                                                
    pointers_struct.cursorY++;                                                                    
  }
  update_cursor();
  new_line_check();
}
