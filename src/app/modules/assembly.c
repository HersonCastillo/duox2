#include "../libraries/assembly.h"

void outportb(ushort port, _string data){
	__asm__ __volatile__(
	  "outb %1, %0"
	  : : "dN" (port), "a" (data)
	);
}

_string inportb(ushort port){
  _string rv;
  __asm__ __volatile__(
	  "inb %1, %0"
	  : "=a" (rv) : "dN" (port)
	);
  return rv;
}
