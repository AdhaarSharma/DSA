#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string strings[1000]{};
    string queries[1000]{};
    int n, b, matches=0;
    string a;
    cin>>n;
    vector<int>z;
    for(int i=0; i<n; i++){
        cin>>a;
        strings[i]=a;
    }
    cin>>b;
    for(int i=0; i<b; i++){
        cin>>a;
        queries[i]=a;
    }
    for(int i=0; i<b; i++){
        for(int j=0; j<n; j++){
            if(queries[i].compare(strings[j])==0)
                matches++;
        }
        z.push_back(matches);
        matches=0;
    }
    for(int i=0; i<b; i++){
        cout<<z[i]<<endl;
    }
    return 0;
}