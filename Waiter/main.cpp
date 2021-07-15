#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, q, v;
    vector<int>prime_vec;
    stack<int>stk1,stk2,stk3;
    cin>>n>>q;
    int prime[10001]{0};
    prime[0]=1;
    prime[1]=1;
    for(int i=2; i<=10000; i++){
        if(prime[i]==0){
            for(int j=i*i; j<=10000;j+=i){
                prime[j]=1;
            }
        }
        if(prime[i]==0)
            prime_vec.push_back(i);
    }
    for(int i=0; i<n; i++){
        cin>>v;
        stk1.push(v);
    }
    for(int i=0;i<q;i++){
        if(stk1.empty())
            break;
        while(!stk1.empty()){
            if(stk1.top()%prime_vec[i]==0){
                stk2.push(stk1.top());
                stk1.pop();
            }
            else{
                stk3.push(stk1.top());
                stk1.pop();
            }
        }
        while(!stk2.empty()){
            cout<<stk2.top()<<endl;
            stk2.pop();
        }
        stk1=stk3;
        while(!stk3.empty())
            stk3.pop();
    }
    while(!stk1.empty()){
        cout<<stk1.top()<<endl;
        stk1.pop();
    }
    return 0;
}
