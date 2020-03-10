#include "../libraries/bootstrap.h"
#include "../libraries/screen.h"
#include "../libraries/cursor.h"
#include "../libraries/keyboard.h"
#include "../libraries/string.h"

void bootstrap() {
  clear_screen();

  const strings command = { (void *) 0 };
  unsigned int index = 0;

  print(trim("     Hola     adios  "));

  while (1) {
    print("$ ");
    command[index] = scanft();
        
    command[index] = 0;
    command[++index] = (void *) 0;
    
    break_line();
  }
}
