#include <utility>
#include <vector>
#include <iostream>
using namespace std;

class FriendlyTrees{
public:
    int countConnectedGroups(int N, vector<pair<int,int>> edges){
        vector<vector<int>> adj(N);
        int n = edges.size();

        for(int i = 0; i < n; i ++){
            int a = edges[i].first;
            int b = edges[i].second;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<bool> visited(N, false);
        int components = 0;

        for (int i = 0; i < N; i++){
            if (!visited[i]){
                dfs(i, adj, visited);
                components++;
            }
        }
        return components;
    }
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited){
        visited[node] = true;
        for (int neighbour : adj[node]){
            if (!visited[neighbour]){
                dfs(neighbour, adj, visited);
            }
        }
    }

};

int main() {
    FriendlyTrees solver;

    // Example 1: Two groups (0-1-2) and (3-4)
    vector<pair<int,int>> edges1 = {{0,1}, {1,2}, {3,4}};
    cout << solver.countConnectedGroups(5, edges1) << endl; // Expected: 2

    // Example 2: One big group (0-1-2-3-4)
    vector<pair<int,int>> edges2 = {{0,1}, {1,2}, {2,3}, {3,4}};
    cout << solver.countConnectedGroups(5, edges2) << endl; // Expected: 1

    // Example 3: All nodes isolated
    vector<pair<int,int>> edges3 = {};
    cout << solver.countConnectedGroups(4, edges3) << endl; // Expected: 4

    // Example 4: Three separate pairs (0-1), (2-3), (4-5)
    vector<pair<int,int>> edges4 = {{0,1}, {2,3}, {4,5}};
    cout << solver.countConnectedGroups(6, edges4) << endl; // Expected: 3

    return 0;
}