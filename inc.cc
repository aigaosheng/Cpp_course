#include "iostream"

using namespace std;

int main() {
 int k = 0;
 cout<<"initial: "<<k<<endl; 
 int k1 = ++k;
 cout<<"++k: "<<k<<endl; 
 cout<<"k1 = "<<k1<<endl;
 int k2 = k++;
 cout<<"k++: "<<k<<endl; 
 cout<<"k2 = "<<k2<<endl;
 
 return 0;
} 
