#include <iostream>
#include <string>
using namespace std;

int main(){
    char a = 'a';
    string str1 = "backlash";
    str1 += a;
    char b = str1[3];
    cout<<b<<endl;
    string str = "Hello";
	cout<<str<<endl;
	return 0;
}
