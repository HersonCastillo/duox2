#ifndef _DEFINITIONS_H_

#define _DEFINITIONS_H_

  #define NULL    (void *) 0
  #define null    0
  
  enum bool { false, true };
  typedef unsigned short ushort;
  typedef unsigned char _string;
  typedef _string *string;
  typedef string *strings;
  typedef void (*callback) (const string args);

#endif