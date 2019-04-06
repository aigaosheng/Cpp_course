#include "iostream"

using namespace std;

int main() {
 int a[5] = {10, 20, 30, 40, 50};
  
  int sum = 0; 
  for(int i = 0; i<5; i++) {
    cout<<"i = "<<a[i]<<endl;
    sum += a[i];
  }
  cout<<"sum of a: "<<sum<<endl; 

  char x='a';
  cout<<(char)(x-32)<<endl;
 
 return 0;
} 
