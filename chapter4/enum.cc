#include <iostream>
using namespace std;


int main()
{
    enum week { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

    week today;
    today = Wednesday;
    cout << "Day " << today <<endl;


    enum weekNew { Sunday2 = 1, Monday2= 3, Tuesday2= 8, Wednesday2= -1, Thursday2 = 7, Friday2 = 10, Saturday2=0 };

    weekNew today2;
    today2 = Wednesday2;
    cout << "Day " << today2 <<endl;
    return 0;
}
