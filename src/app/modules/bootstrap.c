#include "../libraries/bootstrap.h"
#include "../libraries/screen.h"
#include "../libraries/cursor.h"
#include "../libraries/keyboard.h"

void bootstrap() {
    clear_screen();
    
    unsigned char *command = (void *) 0;
    
    print("$ ");
    command = scanft();

    print(command);
}