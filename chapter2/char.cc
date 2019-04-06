#include "iostream"

using namespace std;

int main() {

   char ch;
   cout<<"Input a char: ";
   cin>>ch;
   cout<<"Input character: "<<ch<<endl;
   char xxx[3];
   xxx[0] = ch; 
   if (ch >= 'a' && ch <= 'z') {
     cout<<"lower alphabet"<<endl; 
     ch -= 32;
     xxx[0] -= 32;
   } 
   else if (ch >= 'A' && ch <= 'Z'){
     cout<<"upper alphabet"<<endl;
     xxx[0] += 32;
   } 
   else if (ch>='0' && ch<='9'){
     cout<<"digital"<<endl; 
     xxx[0] = ch;
   } 
   else {
     xxx[0] = ch; 
     cout<<"input not alphabet and digital"<<endl;
   }
   cout<<endl<<xxx[0]<<endl; 
   return 0;
}
