#include <bits/stdc++.h>

using namespace std;

float sqrtNumber(int n, int p){
    int start=0, end=n;
    int mid;
    float ans;
    while(start<=end){
        mid = (start+end)/2;
        if(mid*mid == n){
            ans = mid;
            break;
        }
        else if(mid*mid<n){
            start = mid+1;
            ans = mid;
        }
        else{
            end = mid-1;
        }
    }
    float inc = 0.1;
    for(int i=0; i<p; i++){
        while(ans*ans<=n){
            ans+=inc;
        }
        ans = ans - inc;
        inc = inc/10;
    }
    return ans;
}

int main()
{
    cout<<sqrtNumber(49, 1)<<endl;
    cout<<sqrtNumber(10, 3)<<endl;
    return 0;
}