/*
demo do while loop 
*/
#include<iostream> 
using namespace std; 

int main() 
{ //block 0
	const char name[64] = "coding is a skill";
	
	int name_len = sizeof(name);
	cout<<"name length: "<<name_len<<endl<<endl;
	cout<<"Demo Do .... while ]n"<<endl<<endl;
	int loc = 0;
	do {
		if(name[loc] == ' '){
			cout<<endl;
		}
		else {
			cout<<name[loc];
		}
		loc += 1;		
	} while(loc < name_len);
	
	cout<<"\n\nDemo While ...\n"<<endl;
	//int loc = 0;
	loc = 0;
	while(loc < name_len) {
		if(name[loc] == ' '){
			cout<<endl;
		}
		else {
			cout<<name[loc];
		}
		loc += 1;		
	} 
	
	cout<<"\n\nDemo for ...\n"<<endl;	
	for(loc = 0; loc < name_len; loc++) {
		if(name[loc] == ' '){
			cout<<endl;
		}
		else {
			cout<<name[loc];
		}
	} 
        cout<<endl;	
	
}
