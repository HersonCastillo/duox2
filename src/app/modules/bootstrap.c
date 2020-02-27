#include "../libraries/bootstrap.h"
#include "../libraries/screen.h"
#include "../libraries/cursor.h"
#include "../libraries/keyboard.h"

void bootstrap() {
    clear_screen();
    print("Hello World my boy!");
    
    unsigned char *command = scanft();
    print(command);

}