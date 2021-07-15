#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	vector<int>prime_vec;
    int prime[10001]{0};
    prime[0]=1;
    prime[1]=1;
    for(int i=2; i<=30; i++){
        if(prime[i]==0){
            for(int j=i*i; j<=30;j+=i){
                prime[j]=1;
            }
        }
        if(prime[i]==0)
            prime_vec.push_back(i);
    }
    for(int i; i<prime_vec.size(); i++){
        cout<<prime_vec[i]<<endl;
    }
    return 0;
}
