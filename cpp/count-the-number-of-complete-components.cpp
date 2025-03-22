class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> conn(n,0);
        // convert edges into graph and store the number of edges connected into the minimum of the two vertices
        for (auto& vec:edges) {
            int u = vec[0];
            int v = vec[1];
            conn[min(u,v)]++;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> vis(n,0);
        int compo = 0;
        // use dfs to track the number of connected components along with which component connected to
        for (int i=0;i<n;i++) {
            if (!vis[i]) {
                compo++;
                dfs(vis,i,graph,compo);
            }
        }
        // map to store the number of edges to a connected components
        unordered_map<int,int> mp;
        for (int i=0;i<n;i++) {
            mp[vis[i]]+=conn[i];
        }
        sort(vis.begin(),vis.end());
        int prev = vis[0];
        int cnt = 1;
        int ans = 0;
        // check the complete connected components as it would have nC2 edges
        for (int i=1;i<n;i++) {
            if (vis[i]!=prev) {
                if (cnt==1) ans++;
                else if (mp[prev]==(1LL*cnt*(cnt-1))/2) ans++;
                cnt = 1;
                prev = vis[i];
            }
            else {
                cnt++;
            }
        }
        if (cnt==1) ans++;
        else if (mp[prev]==(1LL*cnt*(cnt-1))/2) ans++;
        return ans;
    }
    private:
    void dfs(vector<int> &vis,int vertex,vector<vector<int>> &graph,int &compo) {
        vis[vertex]=compo;
        for (auto &node:graph[vertex]) {
            if (!vis[node]) {
                dfs(vis,node,graph,compo);
            }
        }
    }
};
