#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char **argv)
{
    int n;
    cin>>n;
    int prime[n+1]{};
	for(int i=0; i<n; i++)
        prime[i]=1;
    prime[0]=0;
    prime[1]=0;
    for(int i=2; i<=sqrt(n); i++){
        if(prime[i]==1){
            for(int j=2; i*j<=n; j++)
                prime[i*j]=0;  
        }
    }
    
    for(int i=0; i<=n; i++)
        cout<<prime[i]<<endl;
	
    return 0;
}
