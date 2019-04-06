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
    struct student myInfo;
    myInfo.name = "gao";
    myInfo.age = 10;
    myInfo.score = 100;

    cout << "Student information : name: " << myInfo.name <<" ,age:" <<myInfo.age<<" ,score: "<<myInfo.score<<endl;

    typedef struct studentInfo {
       string name;
       int age;
       int score;
    } StudentInfo; 
  
    
    StudentInfo myInfo2;
    myInfo2.name = "gao";
    myInfo2.age = 10;
    myInfo2.score = 100;
    cout<<endl<<"Example 2"<<endl;
    cout << "Student information : name: " << myInfo2.name <<" ,age:" <<myInfo2.age<<" ,score: "<<myInfo2.score<<endl;
    return 0;
}
