#include "iostream"
#include "string.h"

void helloMsg(char*);

void helloMsg(char* out) {
  char msg[] = "hello msg: hello world !"; 
  memcpy(out, msg, sizeof(msg)); 
} 
