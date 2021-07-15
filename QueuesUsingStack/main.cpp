#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    int t;
    cin>>t;
    stack<int> stk1;
    stack<int> stk2;
    while(t--){
        int x;
        cin>>x;
        switch (x) {
            case 1:
                int ele;
                cin>>ele;
                stk1.push(ele);
                break;
            case 2:
                if(stk2.empty()){
                    if(stk1.empty()){
                        cout<<"Queue Underflow";
                        exit(1);
                    }
                    else{
                        while(!stk1.empty()){
                            stk2.push(stk1.top());
                            stk1.pop();
                        }
                        stk2.pop();
                    }
                }
                else{
                    stk2.pop();
                }
                break;
            case 3:
                if(stk2.empty()){
                    if(stk1.empty()){
                        cout<<"Queue is Empty"<<endl;
                        exit(1);
                    }
                    else{
                        while(!stk1.empty()){
                            stk2.push(stk1.top());
                            stk1.pop();
                        }
                        cout<<stk1.top()<<endl;
                    }
                }
                else{
                    cout<<stk2.top()<<endl;
                }
        }
    }
    return 0;
}
