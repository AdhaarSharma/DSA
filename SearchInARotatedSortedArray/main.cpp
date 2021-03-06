//2 CODES ARE PRESENT:-
//METHOD-2: Using 1 traversal
class Solution {
public:
    int search(vector<int>& nums, int target) {

        //For fast I/O in C++
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int mid;
        
        //Iterative binary search
        while(left<=right)
        {
            mid = (left+right)/2;
            //cout<<nums[mid]<<"\n";
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>=nums[left])
            {
                if(target<=nums[mid] && target>=nums[left])
                    right = mid-1;
                else
                    left = mid+1;
            }
            else
            {
                if(target>=nums[mid] && target<=nums[right])
                    left = mid+1;
                else
                    right = mid-1;
            }
        }
        return -1;
    }
};

//METHOD-1: Using 2 traversals
class Solution {
    int find_pivot(vector<int>& nums,int left,int right)
    {
        if(nums[left] < nums[right])
            return 0;
        
        int mid;
        //Iterative binary search
        while(left<right)
        {
            mid = (left+right)/2;
            if(nums[mid]>nums[mid+1])
                return mid;
            else if(nums[mid]<nums[0])
                right = mid;
            else
                left = mid+1;
        }
        return mid;
    }
    
    int binary_search(vector<int>& nums,int left,int right,int target)
    {
        int mid;
        //Iterative binary search
        while(left<=right)
        {
            mid = (left+right)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                right = mid-1;
            else
                left = mid+1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        //For Fast I/O in C++
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size();
        if(n==0)
            return -1;
        else if(n==1)
            return nums[0]==target?0:-1;
        
        int pivot = find_pivot(nums,0,n-1);
        if(nums[pivot]==target)
            return pivot;
        
        return target>nums[n-1]?binary_search(nums,0,pivot,target):binary_search(nums,pivot+1,n-1,target);
    }
};