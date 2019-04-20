#include <fstream>      // std::ifstream, std::ofstream
#include <iostream>
using namespace std;

int main () {
  // *************** Write-read text *****
  
  //write file
  char txtFileName[] = "rwb_text.txt";
  ofstream outfile (txtFileName, ios::binary);

  int buffer = 10;
  // write to outfile
  cout<<"Write 1 integer: "<<buffer<<endl;
  outfile<<buffer<<endl;
  char buffer2[] = "hello";
  // write to outfile
  cout<<"Write a string with 5 chars: "<<buffer2<<endl;
  outfile<<buffer2<<endl;

  outfile.close();
  
  //read file
  ifstream inputfile (txtFileName, ios::binary);
  int buffer3;

  inputfile>>buffer3;
  cout<<"read integer: "<<buffer3<<endl;
  char buffer4[20];
  inputfile>>buffer4;
  cout<<"read 5 char :"<<buffer4<<endl;
  inputfile.close();

  return 0;
}
