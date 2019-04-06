#include<iostream> 
using namespace std; 
int main() 
{ //block 0
    //scope 0
    int age = 18; //aage accessable in block 1 & 2
    cout<<"Age is: "<<age<<endl; 
    for(int k= 0; k < 2; k++)  { //block 1, k accessable only in block 1
        cout<<"scope 1: age "<<", "<<age<<endl;
    } 
	    
    for(int k= 0; k < 2; k++)  { //block 2, k accessable in block 2 
        int age = 180;
        cout<<"scope 2 "<<", "<<age<<endl;
    } 
    return 0; 
}

