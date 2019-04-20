// basic file operations
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main () {
  FILE *myfile;
  myfile=fopen ("data.bin", "rb");
  if(myfile == NULL) {
    cout<<"File not exist"<<endl;
  }
  int k;
  fread(&k, sizeof(int), 1, myfile);
  cout<<k<<endl;
  float f[3];
  fread(f, sizeof(float), 3, myfile);
  cout<<f[0]<<", "<<f[1]<<", "<<f[2]<<endl;
  fclose(myfile);
  
  return 0;
}
