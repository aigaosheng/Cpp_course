#include<iostream> 
using namespace std; 
void func() 
{    
    // this variable is local to the 
    // function func() and cannot be  
    // accessed outside this function 
    int age=18;     
} 

int func2() 
{    
    // this variable is local to the 
    // function func() and cannot be  
    // accessed outside this function 
    int age=18; 
	return age;    
} 

int main() 
{ 
    cout<<"Age is: "<<age;
	//cout<<"Age is: "<<func2();        
    return 0; 
}

