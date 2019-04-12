#include <iostream>

using namespace std;

int main() {
  int x=10;
  int *xp = &x;

  float *y = new float[3];
   y[0]=1.2;
   y[1]= 2.2;
   y[2]= 3.2;
 // float y[3] = {1.2, 2.2, 3.2};
  float *yp = y; //array its name is first address
 
  cout<<"x "<<x<<endl;
  cout<<"xp "<<*xp<<endl;  
  cout<<"y "<<y[0]<<endl;
  cout<<"yp "<<*yp<<endl;
  cout<<"yp1 "<<*(yp+1)<<endl;
  cout<<"yp1 a "<<yp[1]<<endl;
  cout<<"yp "<<*yp<<", "<<*(yp++)<<", "<<*(yp++)<<endl;
  
  yp = &y[0]; 
  cout<<"yp "<<*yp<<", "<<*(++yp)<<", "<<*(++yp)<<endl;
  
  cout<<"y "<<*y<<", "<<*(y+1)<<", "<<*(y+2)<<endl;
  

   delete [] y; 
  return 1;
}  
