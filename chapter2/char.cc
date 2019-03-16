#include "iostream"

using namespace std;

int main() {

   char ch;
   cout<<"Input a char: ";
   cin>>ch;
   cout<<"Input character: "<<ch<<endl;
   
   if (ch >= 'a' && ch <= 'z')
     cout<<"lower alphabet"<<endl; 
   else if (ch >= 'A' && ch <= 'Z')
     cout<<"upper alphabet"<<endl;
   else if (ch>='0' && ch<='9')
     cout<<"digital"<<endl; 
   else
     cout<<"input not alphabet and digital"<<endl;
   return 0;
}
