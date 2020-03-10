#include "../libraries/string.h"

ushort strlength(string message) {
  ushort index = 0;         
  while (message[index++]);  
  return index;
}

ushort strcompare(string first, string second) {
  ushort result = false;
  ushort first_len = strlength(first);
  ushort second_len = strlength(second);

  if (first_len == second_len) {
    result = true;
    ushort index = -1;
    while (first[++index] && result) {
      result = first[index] == second[index] ? true : false;
    }
  }

  return result;
}

string trim(string message) {
  ushort index = -1;
  ushort message_len = strlength(message);
  char first_case = message[0];
  char last_case = message[message_len - 1];
  string new_message = "";

  if (first_case == ' ') {
    for (int index = 1, manager = 0; index < message_len; index++, manager++) {
      new_message[manager] = message[index];
    }
    return trim(new_message);
  }
  if (last_case == ' ') {
    for (int index = 0; index < message_len - 1; index++) {
      new_message[index] = message[index];
    }
    return trim(new_message);
  }

  return message;
}

ushort letters_count(string message) {
  ushort index = -1;
  ushort letters = 0;
  while (message[++index]) {
    if (message[index] != ' ') {
      letters++;
    }
  }
  return letters;
}
