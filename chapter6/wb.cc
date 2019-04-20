// basic file operations
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

int main () {
  ofstream myfile;
  myfile.open ("data.bin", ios::binary);
  int k=10;
  cout<<sizeof(k)<<endl;
  myfile.write((char*)&k, sizeof(k));
  float f[3] = {1.0, 2.0, 3.0};
  cout<<sizeof(f)<<endl;
  myfile.write((char*)f, sizeof(f));
  myfile.close();
  
  return 0;
}
