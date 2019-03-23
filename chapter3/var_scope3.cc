/*
demo global variable declare 
*/
#include<iostream> 
using namespace std; 
int age = 18; //global variable, can be accessed anywhere

int main() 
{ //block 0
    cout<<"Block 0: Global variable: Age is : "<<age<<endl;
    
    { //block 1
		int age = 28; //local variable 
    	cout<<"Local scope variable 1: Age is : "<<age<<endl;
    	{ //block 2
    		cout<<"block 2: Local scope variable in block 1: Age is : "<<age<<endl;
    		int age=38;
    		cout<<"Block 2: Local scope variabl block 2: Age is : "<<age<<endl;
    		cout<<"Global variable in block 2: Age is : "<<::age<<endl;
		}
    }
    { //block 3
    	cout<<"block3: Global  variable: Age is : "<<age<<endl;
	}
    return 0; 
}

