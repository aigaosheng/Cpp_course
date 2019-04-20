// basic file operations
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

int main () {
  ofstream myfile;
  myfile.open ("doc.txt");
  myfile << "Line 1.\n";
  myfile << "Line 2.";
  myfile << " 在美涉2亿30\n";
  myfile.close();
  
  return 0;
}
