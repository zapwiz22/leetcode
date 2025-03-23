class Solution {
    const int MOD = 1e9 + 7;

public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n);
        // creating the graph
        for (auto& vec : roads) {
            graph[vec[0]].emplace_back(vec[1], vec[2]);
            graph[vec[1]].emplace_back(vec[0], vec[2]);
        }
        // priority queue for mainting the minimal of {time,vertex}
        priority_queue<pair<long long, long long>,
                       vector<pair<long long, long long>>, greater<>>
            pq;
        // vector to store the current found shortestTime for a vertex
        vector<long long> shortestTime(n, LLONG_MAX);
        // vector to store the number of paths with equal time to a vertex
        vector<long long> paths(n, 0);
        shortestTime[0]=0;
        paths[0]=1;
        pq.emplace(0, 0);
        while (!pq.empty()) {
            long long curr = pq.top().second;
            long long currtime = pq.top().first;
            pq.pop();
            if (currtime > shortestTime[curr])
                continue;
            for (auto& pr : graph[curr]) {
                if (currtime + pr.second < shortestTime[pr.first]) {
                    shortestTime[pr.first] = currtime + pr.second;
                    paths[pr.first] = paths[curr];
                    pq.emplace(shortestTime[pr.first], pr.first);
                } else if (currtime + pr.second == shortestTime[pr.first]) {
                    paths[pr.first]=(paths[pr.first]+paths[curr])%MOD;
                }
            }
        }
        return paths[n-1];
    }
};
