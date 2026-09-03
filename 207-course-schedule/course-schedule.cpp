class Solution {
public:

    bool dfs(int node, vector<int>&vis, vector<int>&dfsVis, vector<vector<int>>&adj){
        vis[node]=1;
        dfsVis[node]=1;
        for(auto &it: adj[node]){
            if(!vis[it]){
                if(dfs(it, vis, dfsVis, adj)){
                    return true;
                }
            }
            else if(dfsVis[it]){
                return true;
            }
        }
        dfsVis[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto &edge: prerequisites){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        vector<int>vis(numCourses,0);
        vector<int>dfsVis(numCourses,0);

        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
                if(dfs(i, vis, dfsVis, adj) == true){
                    return false;
                }
            }
        }
        return true;
    }
};