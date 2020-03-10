#include "../libraries/cmd.h"
#include "../libraries/string.h"

const string commands[] = {
  "help", '\0'
};

const callback functions[] = {
  help
};

void eval(string command) {
  ushort index = -1;
  while (commands[++index]) {
    string current_command = trim(commands[index]);
    if (strcompare(trim(command), current_command)) {
      functions[index](0);
    }
  }
}
