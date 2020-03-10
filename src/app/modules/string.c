#include "../libraries/string.h"

unsigned short strlength(string message) {
  unsigned short index = 0;         
  while (message[index++]);  
  return index;
}
