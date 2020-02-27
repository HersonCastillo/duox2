#include "../libraries/bootstrap.h"
#include "../libraries/screen.h"
#include "../libraries/cursor.h"
#include "../libraries/keyboard.h"

void bootstrap() {
    clear_screen();
    
    unsigned char *command = (void*) 0;
    while (1) {
        print("$ ");
        command = scanft();
        command = (void *) 0;
    }

}