#include <bits/stdc++.h>

using namespace std;

int main()
{
    int c1=0, c2=0;
    for(int i=1; i<101; i++){
        string d;
        c1++;
        c2++;
        if(c1==3){d+="fizz"; c1=0;}
        if(c2==5){d+="buzz"; c2=0;}
        if(d=="")
            cout<<i<<endl;
        else
            cout<<d<<endl;    
    }
}
