#include <iostream>
#include "add2.h"

int add(int x, int y) {
   int z;
   z=x+y;  
   return z; 
}

int main() {
   int c;
   int x=4;
   int y=5;
   //int (*fadd)(int,int) = add;
   c = add(x, y); //call function
   std::cout<<"x+y: "<<x<<" + "<<y<<" = "<<c<<std::endl;
   c = add2(x); //call function
   std::cout<<"x+y: "<<x<<" + 20"<<" = "<<c<<std::endl;
   //std::cout<<"x+y ="<<fadd(5, 6)<<std::endl;

   return 1; 
}

int add2(int x, int y) { //function 
    int  z = x + y;
    return z; 
}

