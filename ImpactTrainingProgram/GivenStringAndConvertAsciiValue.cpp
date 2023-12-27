
#include <iostream>
using namespace std;

int main()
{
	int asciiValue;
	cout<<"Enter ASCII: \n";
	cin>>asciiValue;
   char ch = static_cast<char>(asciiValue);
	cout<<"Corresponding character is: "<<ch<<endl;
	return 0;
}
