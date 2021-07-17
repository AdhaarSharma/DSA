class Solution {
    public:
    bool kahnAlgo(vector<int> &indegree, vector<vector<int>> &adj, int n, vector<int> &ans){
        
        queue<int> q;
        for(int i=0; i<n; i++)
            if(indegree[i]==0)
                q.push(i);
    
        int count = 0;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            for(auto x : adj[curr]){
                indegree[x]-=1;
                if(indegree[x]==0)
                    q.push(x);
            }
            ans.push_back(curr);
            count+=1;
        }
        
        if(count!=n)
            return false;
        return true;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        
        for(int i=0; i<n; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]+=1;
        }
        
        vector<int>ans;
        if(kahnAlgo(indegree,adj,numCourses,ans))
            return ans;
            
        return {};
    }
};