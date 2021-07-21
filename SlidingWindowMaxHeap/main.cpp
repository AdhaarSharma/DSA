#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> slidingWindowMax(vector<int> &nums, int k){
    vector<int> ans;
    priority_queue<pair<int,int>> heap;
    
    for(int i=0; i<nums.size(); i++){
        while(!heap.empty() && heap.top().second<=(i-k))
            heap.pop();
        heap.push(make_pair(nums[i],i));
        if(i>=k-1)
            ans.push_back(heap.top().first);
    }
    return ans;
}

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
