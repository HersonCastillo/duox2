#include "../libraries/bootstrap.h"
#include "../libraries/screen.h"
#include "../libraries/cursor.h"
#include "../libraries/keyboard.h"
#include "../libraries/string.h"
#include "../libraries/cmd.h"

void bootstrap() {
  clear_screen();

  const strings command = { (void *) 0 };
  unsigned int index = 0;

  while (1) {
    print("$ ");
    command[index] = scanft();
    
    eval(command[index]);

    command[index] = 0;
    command[++index] = (void *) 0;
    
    break_line();
  }
}
