#include <bitset>
#include <iostream>
using namespace std;

int main() {
	int i;
	cin>>i;
 	bitset<32> x;
	cout<<i<<"  "<<bitset<32>(i)<<endl;
	cout<<-i<<" "<<bitset<32>(-i)<<endl;
	cout<<~i<<" "<<bitset<32>(~i)<<endl;

	cout<<i<<" "<<(i&-(i))<<endl;

     int k = i;
     while(i>0){
		i -= (i & (-i));
		cout<<" *"<<i<<" "<<bitset<16>(i)<<endl;
	 }
     cout<<"++"<<endl;
     i = k;
     while(i<=16){
		i += (i & (-i));
		cout<<" *"<<i<<" "<<bitset<16>(i)<<endl;
	}

}
