// basic file operations
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

int main () {
  char *msg = new char[128];
  ifstream myfile;
  myfile.open ("doc.txt");
  while(!myfile.eof()) {
    myfile.getline(msg, 128);
    cout<<msg<<endl;
  }
  myfile.close();
 
  return 0;
}
