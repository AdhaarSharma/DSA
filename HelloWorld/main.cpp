#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
   char a[5]="abc";
    
    cout<<sizeof(a);
    cout<<endl;
    
    string s;
    s=a;
    cout<<s.length();
    cout<<endl;
    cout<<s.size();
    cout<<endl;
    
    string b[3];
    cout<<"Size of string :"<<s.size()<<endl;
    b[0]="abcd";
    cout<<"Size of string :"<<s.length()<<endl;
    char str[20];
    str[0] = 'a';
    str[1] = 'b';
    str[2] = 'c';
    str[3] = 'd';
    cout<<"Char Array: "<<str;
    getch();
    return 0;
}