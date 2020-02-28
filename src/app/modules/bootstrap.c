#include "../libraries/bootstrap.h"
#include "../libraries/screen.h"
#include "../libraries/cursor.h"
#include "../libraries/keyboard.h"

void bootstrap() {
    clear_screen();
    
    unsigned char **command = { (void *) 0 };
    unsigned long long index = 0;
    
    cmd:
        print("$ ");
        command[index] = scanft();
        command[index] = 0;
        index++;
        goto cmd;
}