#include "../libraries/cursor.h"
#include "../libraries/keyboard.h"
#include "../libraries/assembly.h"

unsigned char *scanft() {
    unsigned char* buffstr;
    unsigned short index = 0;
    unsigned short reading = 1;
    while (reading) {
        if (inportb(0x64) & 0x1) {
            switch (inportb(0x60)) { 
                case 2:
                    print_char('1');
                    buffstr[index] = '1';
                    index++;
                break;
                case 3:
                    print_char('2');
                    buffstr[index] = '2';
                    index++;
                break;
                case 4:
                    print_char('3');
                    buffstr[index] = '3';
                    index++;
                break;
                case 5:
                    print_char('4');
                    buffstr[index] = '4';
                    index++;
                break;
                case 6:
                    print_char('5');
                    buffstr[index] = '5';
                    index++;
                break;
                case 7:
                    print_char('6');
                    buffstr[index] = '6';
                    index++;
                break;
                case 8:
                    print_char('7');
                    buffstr[index] = '7';
                    index++;
                break;
                case 9:
                    print_char('8');
                    buffstr[index] = '8';
                    index++;
                break;
                case 10:
                    print_char('9');
                    buffstr[index] = '9';
                    index++;
                break;
                case 11:
                    print_char('0');
                    buffstr[index] = '0';
                    index++;
                break;
                case 12:
                    print_char('-');
                    buffstr[index] = '-';
                    index++;
                break;
                case 13:
                    print_char('=');
                    buffstr[index] = '=';
                    index++;
                break;
                case 14:
		            if(index > 0){
		                print_char('\b');
		                index--;
		                buffstr[index] = 0;
		            }
                break;
                case 16:
                    print_char('q');
                    buffstr[index] = 'q';
                    index++;
                break;
                case 17:
                    print_char('w');
                    buffstr[index] = 'w';
                    index++;
                break;
                case 18:
                    print_char('e');
                    buffstr[index] = 'e';
                    index++;
                break;
                case 19:
                    print_char('r');
                    buffstr[index] = 'r';
                    index++;
                break;
                case 20:
                    print_char('t');
                    buffstr[index] = 't';
                    index++;
                break;
                case 21:
                    print_char('y');
                    buffstr[index] = 'y';
                    index++;
                break;
                case 22:
                    print_char('u');
                    buffstr[index] = 'u';
                    index++;
                break;
                case 23:
                    print_char('i');
                    buffstr[index] = 'i';
                    index++;
                break;
                case 24:
                    print_char('o');
                    buffstr[index] = 'o';
                    index++;
                break;
                case 25:
                    print_char('p');
                    buffstr[index] = 'p';
                    index++;
                break;
                case 26:
                    print_char('[');
                    buffstr[index] = '[';
                    index++;
                break;
                case 27:
                    print_char(']');
                    buffstr[index] = ']';
                    index++;
                break;
                case 28:
                    index++;
                    reading = 0;
                    break;
                case 30:
                    print_char('a');
                    buffstr[index] = 'a';
                    index++;
                break;
                case 31:
                    print_char('s');
                    buffstr[index] = 's';
                    index++;
                break;
                case 32:
                    print_char('d');
                    buffstr[index] = 'd';
                    index++;
                break;
                case 33:
                    print_char('f');
                    buffstr[index] = 'f';
                    index++;
                break;
                case 34:
                    print_char('g');
                    buffstr[index] = 'g';
                    index++;
                break;
                case 35:
                    print_char('h');
                    buffstr[index] = 'h';
                    index++;
                break;
                case 36:
                    print_char('j');
                    buffstr[index] = 'j';
                    index++;
                break;
                case 37:
                    print_char('k');
                    buffstr[index] = 'k';
                    index++;
                break;
                case 38:
                    print_char('l');
                    buffstr[index] = 'l';
                    index++;
                break;
                case 39:
                    print_char(';');
                    buffstr[index] = ';';
                    index++;
                break;
                case 40:
                    print_char((char)44);
                    buffstr[index] = (char)44;
                    index++;
                break;
                case 41:
                    print_char((char)44);
                    buffstr[index] = (char)44;
                    index++;
                break;
                 case 44:
                    print_char('z');
                    buffstr[index] = 'z';
                    index++;
                break;
                case 45:
                    print_char('x');
                    buffstr[index] = 'x';
                    index++;
                break;
                case 46:
                    print_char('c');
                    buffstr[index] = 'c';
                    index++;
                break;
                case 47:
                    print_char('v');
                    buffstr[index] = 'v';
                    index++;
                break;                
                case 48:
                    print_char('b');
                    buffstr[index] = 'b';
                    index++;
                break;               
                case 49:
                    print_char('n');
                    buffstr[index] = 'n';
                    index++;
                break;                
                case 50:
                    print_char('m');
                    buffstr[index] = 'm';
                    index++;
                break;               
                case 51:
                    print_char(',');
                    buffstr[index] = ',';
                    index++;
                break;                
                case 52:
                    print_char('.');
                    buffstr[index] = '.';
                    index++;
                break;            
                case 53:
                    print_char('/');
                    buffstr[index] = '/';
                    index++;
                break;            
                case 54:
                    print_char('.');
                    buffstr[index] = '.';
                    index++;
                break;            
                case 55:
                    print_char('/');
                    buffstr[index] = '/';
                    index++;
                break;                    
                case 57:
                    print_char(' ');
                    buffstr[index] = ' ';
                    index++;
                break;
            }
        }
    }
    buffstr[index] = 0;                
    return buffstr;
}
