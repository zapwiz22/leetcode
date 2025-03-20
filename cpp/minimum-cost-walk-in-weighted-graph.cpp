
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<pair<int, int>>> graph(n);
        // storing all the data as an adjacency list 
        for (auto& vec : edges) {
            graph[vec[0]].emplace_back(vec[1], vec[2]);
            graph[vec[1]].emplace_back(vec[0], vec[2]);
        }
        vector<bool> vis(n,0); // visited vector to store which vertex has been visited
        vector<int> components(n); // to check and store the same value for all the vertices which belong to the same connected component
        vector<int> componentCost; // for the same components keep on taking bitwise & and store the final answer as the index stored for all the vertices in the same connected component
        int componentId = 0; // the id which will be stored for the vertices of the connected component
        for (int i=0;i<n;i++) {
            // if vertex not visited ==> new component
            if (!vis[i]) {
                componentCost.push_back(getComponentCost(i,graph,vis,components,componentId));
                componentId++;
            }
        }
        // processing each query
        vector<int> ans;
        for (auto &query:query) {
            int start = query[0];
            int end = query[1];
            // if both belongs to same component then answer exists else -1
            if (components[start]==components[end]) {
                ans.push_back(componentCost[components[start]]);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
private:
    // dfs like function to return the & of all the components of a single connected component
    int getComponentCost(int vertex,vector<vector<pair<int,int>>> &graph,vector<bool>& vis,vector<int> &components,int componentId) {
        int currCost = INT_MAX; // so all the bits are set to 1
        components[vertex]=componentId;
        vis[vertex]=true;
        for (auto& [neighbour,wt]:graph[vertex]) {
            currCost &= wt;
            if (!vis[neighbour]) {
                currCost &= getComponentCost(neighbour,graph,vis,components,componentId);
            }
        }
        return currCost;
    }
};

