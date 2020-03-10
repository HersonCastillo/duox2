#ifndef _ASSEMBLY_H_

#define _ASSEMBLY_H_

  #include "definitions.h"

  void outportb(unsigned short port, _string data);
  _string inportb(unsigned short port);

#endif
