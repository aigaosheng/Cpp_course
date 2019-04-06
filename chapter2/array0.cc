#include "iostream"

using namespace std;

int main() {

   int X[5];
   int a = 10;
   
   //initialization
   for (int k=0; k<5; k++) {
       X[k] = a * (k+1);
   }

   //get odd position
   for(int k=0;k<5; k+=2) {
      cout<<X[k]<<", ";
   }
   cout<<endl;
   return 0;
}
