#include <iostream>
#include <string.h>
using namespace std;
int main () {
   // local variable declaration:
   char a[] = "c++";
    // check the boolean condition
   if(strcmp(a, "c++") == 0) {
      // if condition is true then print the following
      cout << "Learning C++;" << endl;
   }
   else {
       cout << "Learning other languages: " << a << endl;
   } 


   if(strncmp(a, "c++", 3) == 0) {
      // if condition is true then print the following
      cout << "Learning C++;" << endl;
   }
   else {
       cout << "Learning other languages: " << a << endl;
   }

   return 0;
}

