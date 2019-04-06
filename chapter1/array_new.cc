#include "iostream"
#include "cstring"

using namespace std;

int main() {
 int *a = new int[5];
 if(!a) {
   cout<<"Warning: allocate memory error"<<endl;
   exit(-1);
 } 
 a[0] = 10;
 a[1] = 20;
 a[2] = 30;
 a[3] = 40;
 a[4] = 50;
  
  int sum = 0; 
  for(int i = 0; i<5; i++) {
    cout<<"i = "<<a[i]<<endl;
    sum += a[i];
  }
  cout<<"sum of a: "<<sum<<endl; 

 delete [] a;  

 char *s = new char[9];
 s[0] = 'h';
 s[1] = 'e';
 s[2] = 'l';
 s[3] = 'l';
 s[4] = 'o';
 //#s[5] = '\n';
 cout<<"string: "<<s<<"  length: "<<strlen(s)<<endl;
 
 int ia = 32;
 
 for (int i = 0; i < strlen(s); i++) {
   cout<<s[i]<<" * integer "<<(int)s[i]<<" +1 "<<(char)(s[i] - ia)<<endl;
}

 delete [] s;


 return 0;
} 
