#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

void splitInfo(const char *info, string &o_nm, string &o_adr, int &o_age); 

int main() {
  char filename[] = "student.txt";
  const int max_len = 256;
  char *ln = new char[max_len];
  //read 
  ifstream ifl;
  ifl.open(filename);
  if(ifl.is_open()) {
    while(!ifl.eof()){
      ifl.getline(ln, 256);
      cout<<ln<<"   string len: "<<strlen(ln)<<endl;
    }
  }
  ifl.close();
  delete [] ln;

  //how to check read string is valid data or comment
  char msg[] = "#student";
  if(msg[0]=='#'){
    cout<<msg<<" is comment line"<<endl<<endl;
  }

  //how to split data string into different field
  string name;
  string adr;
  int age;

  char lnstr[] = "mike li:12:holland abc";
  splitInfo(lnstr, name, adr, age);
  cout<<lnstr<<endl;
  cout<<"name: "<<name<<endl;
  cout<<"age: "<<age<<endl;
  cout<<"address: "<<adr<<endl;

}

void splitInfo(const char *info, string &o_nm, string &o_adr, int &o_age) {
  string su_str[3];
  int count = 0;
  for(int k = 0; k < strlen(info); k++) {
    if(info[k] == ':') {
      count += 1;
    }
    else {
      su_str[count].push_back(info[k]);
  }
  o_nm = su_str[0];
  o_adr = su_str[2];
  sscanf(su_str[1].c_str(), "%d", &o_age);
}
}
