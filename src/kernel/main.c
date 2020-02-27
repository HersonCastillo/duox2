#define MAGIC_NUMBER 0xb8000
#define WIDTH_SCREEN 80
#define HEIGHT_SCREEN 25
#define WHITE_TXT 0x07

#include "../app/libraries/bootstrap.h"

void kernel_main() {
    bootstrap();
}
