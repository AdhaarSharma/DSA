#include <bits/stdc++.h>
#include <string>
using namespace std;

vector<vector<string>> Anagrams(vector<string>& string_list){
    unordered_map<string,vector<string>>  mymap;
    int n=string_list.size();
    string temp;
    for(int i=0; i<n; i++){
        temp = string_list[i];
        sort(temp.begin(),temp.end());
        mymap[temp].push_back(string_list[i]);
    }
    vector<vector<string>> result;
    for(auto itr=mymap.begin(); itr!=mymap.end(); itr++){
        result.push_back(itr->second);
    }
    return result;
}

int main()
{
	printf("hello world\n");
	return 0;
}
