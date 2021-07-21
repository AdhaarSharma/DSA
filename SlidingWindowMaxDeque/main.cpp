#include <bits/stdc++.h>
using namespace std;

vector<int> slidingWindowMax(vector<int> &nums, int k){
    vector<int> ans;
    deque<pair<int,int>> dq;
    for(int i=0; i<nums.size(); i++){
        if(!dq.empty() && dq.front().second<=(i-k))
            dq.pop_front();
        while(!dq.empty() && dq.back().first<nums[i])
            dq.pop_back();
        dq.push_back(make_pair(nums[i],i));
        if(i>=k-1)
            ans.push_back(dq.front().first);
    }
    return ans;
}

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
