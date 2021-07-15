#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x, temp;
    cin>>n>>x;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    
    for(int i=0; i<x; i++){
        temp = a[0];
        for(int j=0; j<n-1; j++){
            a[j] = a[j+1];
        }
        a[n-1] = temp;
    }
    
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
}