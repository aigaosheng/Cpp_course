// basic file operations
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

int main () {
  ifstream myfile;
  myfile.open ("data.bin", ios::binary);
  int k;
  myfile.read((char*)&k, sizeof(int) * 1);
  cout<<k<<endl;
  float f[3];
  myfile.read((char*)f, sizeof(float)*3);
  cout<<f[0]<<", "<<f[1]<<", "<<f[2]<<endl;
  myfile.close();
  
  return 0;
}
