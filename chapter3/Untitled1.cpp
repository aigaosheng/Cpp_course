#include<iostream>
using namespace std;
  // Global age
  int age = 18;
  int main()
  {
  	//Local age
  	int age = 10;
  	cout<<"Value of global age is"<<::age;
  	cout<<endl<<"Value of local eage is"<<age;
  	return 0;
  }
  
