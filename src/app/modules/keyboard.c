#include "../libraries/cursor.h"
#include "../libraries/keyboard.h"
#include "../libraries/assembly.h"

const char CHARS_TREE[] = {
  null, null, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
  '-', '=', null, null, 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i',
  'o', 'p', '[', ']', null, null, 'a', 's', 'd', 'f', 'g', 'h',
  'j', 'k', 'l', ';', (char) 44, (char) 44, null, null, 'z', 
  'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', '.', '/'
};

string scanft() {
  string buffstr = "";
  int index = 0;
  short reading = true;
  while (reading) {
    char keyboardEvent = inportb(0x64) & 0x1;
    if (keyboardEvent) {
      char keyCode = inportb(0x60);
      switch (keyCode) {
        case 14:
		      if(index > 0){
		        print_char('\b');
		        index--;
		        buffstr[index] = 0;
          }
        break;
        case 28:
          reading = false;
        break;
        case 57:
          print_char(' ');
          buffstr[index++] = ' ';
        break;
        case 2: case 3: case 4: case 5: case 6: case 7: case 8:  case 9: case 10: case 11:
        case 12: case 13: case 16: case 17: case 18: case 19: case 20: case 21: case 22:
        case 23: case 24: case 25: case 26: case 27: case 30: case 31: case 32: case 33:
        case 34: case 35: case 36: case 37: case 38: case 39: case 40: case 41: case 44:
        case 45: case 46: case 47: case 48: case 49: case 50: case 51: case 52: case 53:
        case 54: case 55: case 56:
          print_char(CHARS_TREE[keyCode]);
          buffstr[index++] = CHARS_TREE[keyCode];
        break;
      }
    }
  }
  buffstr[index] = 0;
  return buffstr;
}

void break_line() {
  print_char('\n');
}

void delay_break_time(long time, long clock_timer) {
  for (long seconds = 0; seconds < time; seconds++) {
    for (long index = 0; index < clock_timer ; index++);
  }
}
