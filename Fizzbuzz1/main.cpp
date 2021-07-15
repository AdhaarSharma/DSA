#include <bits/stdc++.h>

using namespace std;

int main()
{
    for(int i=1; i<101; i++){
        string d = "";
        if(i%3==0){
            d += "fizz";
        }
        if(i%5==0){
            d += "buzz";
        }
        if(d==""){
            cout<<i<<endl;
        }else{
            cout<<d<<endl;
        }
    }
}
