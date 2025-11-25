#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class TreeAndVertex{
public:
    int get(vector<int> tree){
        int n = tree.size();
        vector<vector<int>> adj(n+1);

        for (int i = 0; i < n; i ++){
            int a = i+1;
            int b = tree[i];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int maxComponent = 0;
        

        for (int i = 0; i < n+1; i++){
            vector<bool> visited(n+1, false);
            int component = 0;
            visited[i] = true;
            for(int j = 0;j < n+1; j++){
                if(!visited[j]){
                    dfs(j, adj, visited);
                    component++;
                }
                maxComponent = max(component, maxComponent);
            }
        }
        return maxComponent;
    }   
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited){
        visited[node] = true;
        for (int neighbour : adj[node]){
            if(!visited[neighbour]){
                dfs(neighbour, adj, visited);
            }
        }
    }
};

int main() {
    TreeAndVertex solver;

    vector<int> tree1 = {0, 0, 0};
    cout << solver.get(tree1) << endl; // Expected 3

    vector<int> tree2 = {0, 1, 2, 3};
    cout << solver.get(tree2) << endl; // Expected 2

    vector<int> tree3 = {0, 0, 2, 2};
    cout << solver.get(tree3) << endl; // Expected 3

    vector<int> tree4 = {0, 0, 0, 1, 1, 1};
    cout << solver.get(tree4) << endl; // Expected 4

    vector<int> tree5 = {0, 1, 2, 0, 1, 5, 6, 1, 7, 4, 2, 5, 5, 8, 6, 2, 14, 12, 18, 10, 0, 6, 18, 2, 20, 11, 0, 11, 7, 12, 17, 3, 18, 31, 14, 34, 30, 11, 9};
    cout << solver.get(tree5) << endl;
    return 0;
}