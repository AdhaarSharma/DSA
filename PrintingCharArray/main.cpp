#include <iostream>
#include <string>
using namespace std;

int main()
{
    char str[20];
    str[0] = 'a';
    str[1] = 'b';
    str[2] = 'c';
    str[3] = 'd';
    cout<<"Char Array: "<<str<<endl;
    char *str1 = "Hello";
    cout<<str1<<endl;
    //char* is pointer and char[] is array
    //char* is read only and char[] is read/write. p[0]='k' is valid only in char
    //"geek" is stored at stack section in char[] 
    //and "geek" is stored at code section in char*
}
