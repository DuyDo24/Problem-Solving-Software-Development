class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int components = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i ++){
            if (!visited[i]){
                components++;
                dfs(i , isConnected, visited);
            }
        }
        return components;
    }
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited){
        visited[node] = true;
        for (int i = 0; i < isConnected.size(); i++ ){
            if (isConnected[node][i] == 1 && !visited[i]){
                dfs(i, isConnected, visited);
            }
        }
    }
};