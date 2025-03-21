class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        // unordered map to store the required number of ingredients for a particular recipe
        unordered_map<string,int> graph;
        for (int i=0;i<recipes.size();i++) {
            graph[recipes[i]] = ingredients[i].size(); 
        }
        // unordered map to store the recipes possible from one ingredient
        unordered_map<string,vector<string>> recipesFromIngs;
        for (int i=0;i<recipes.size();i++) {
            for (auto &ing:ingredients[i]) {
                recipesFromIngs[ing].push_back(recipes[i]);
            }
        }
        // queue storing all the ingredients we have 
        queue<string> q;
        for (auto &str:supplies) {
            q.push(str);
        }
        vector<string> ans;
        while (!q.empty()) {
            string recipe = q.front();
            q.pop();
            if (graph.find(recipe)!=graph.end() && graph[recipe]==0) {
                // if no more ingredients required for a recipe push into ans vector
                ans.push_back(recipe);
            }
            for (auto &rec:recipesFromIngs[recipe]) {
                graph[rec]--;
                if (graph[rec]==0) {
                    // if found a recipe which requires no more ingredients push it into q so that it can be analyzed and finally be pushed into the ans vector
                    q.push(rec);
                }
            }
        }
        return ans;
    }
};
