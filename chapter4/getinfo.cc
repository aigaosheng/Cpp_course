#include <iostream>
#include <string>
using namespace std;


int main()
{
    struct student {
       string name;
       int age;
       int score;
    };  
    struct student myInfo[1];
    int nRecord = 1;
    myInfo[0].name = "gao";
    myInfo[0].age = 10;
    myInfo[0].score = 100;
    
    string myname;
   cin>>myname;
   bool isFound = false;
   for(int k =0; k<nRecord; k++) {
         if(myInfo[k].name == myname) {
            cout << "Student information" << endl<<myInfo[k].name <<" ,age:" <<myInfo[k].age<<" ,score: "<<myInfo[k].score<<endl;
            isFound = true;
            break;
       }
   }
   if(!isFound) {
      cout<<myname<<" not in database"<<endl;
   }
    return 0;
}
