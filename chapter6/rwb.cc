#include <fstream>      // std::ifstream, std::ofstream
#include <iostream>
using namespace std;

int main () {
  // *************** Write-read binary *****
  
  //write file
  char txtFileName[] = "rwb_bin.txt";
  ofstream outfile (txtFileName, ios::binary);

  int buffer = 10;
  // write to outfile
  cout<<"Write 1 integer: "<<buffer<<endl;
  outfile.write((char*)&buffer, sizeof(buffer));
  char buffer2[] = "hello";
  // write to outfile
  cout<<"Write a string with 5 chars: "<<buffer2<<endl;
  outfile.write(buffer2, sizeof(buffer2));

  outfile.close();
  
  //read file
  ifstream inputfile (txtFileName, ios::binary);
  int buffer3;

  inputfile.read((char*)&buffer3, sizeof(buffer3));
  cout<<"read integer: "<<buffer3<<endl;
  char buffer4[20];
  inputfile.read(buffer4, 5);
  cout<<"read 5 char :"<<buffer4<<endl;
  inputfile.close();

  // *************** END ******
  // ------ Write-read text ----

  return 0;
}
