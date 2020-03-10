#ifndef _ASSEMBLY_H_

#define _ASSEMBLY_H_

  #include "definitions.h"

  void outportb(ushort port, _string data);
  _string inportb(ushort port);

#endif
