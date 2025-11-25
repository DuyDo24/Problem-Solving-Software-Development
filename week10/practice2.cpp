#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class FriendlyRooks{
public:
    int getMinFriendlyColoring(vector<string> board){
        int n = board.size();
        int m = board[0].size();
        int total = n + m;
        vector<vector<int>> adj(total);

        for (int i = 0;i <n ;i++){
            for (int j = 0 ; j < m; j++){
                if (board[i][j] == 'R'){
                    adj[i].push_back(j + n);
                    adj[j + n].push_back(i);
                }
            }
        }
        int components = 0;
        vector<bool> visited(total, false);

        for (int i = 0; i < n; i++){
            if (!visited[i] && !adj[i].empty()){
                components++;
                dfs(i, adj, visited);
            }
        }
        return components;
    }  
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited){
        visited[node] = true;
        for (int neighbour : adj[node]){
            if (!visited[neighbour]){
                dfs(neighbour , adj, visited);
            }
        }
    }
};

int main() {
    FriendlyRooks solver;

    vector<string> b0 = {".R.R", "R.R.", ".R.R"};
    cout << solver.getMinFriendlyColoring(b0) << endl; // 2

    vector<string> b1 = {"RRRRRRRRRRRRRRR"};
    cout << solver.getMinFriendlyColoring(b1) << endl; // 1

    vector<string> b2 = {"...............",
                         "...............",
                         "...............",
                         "...............",
                         "...............",
                         "..............."}; 
    cout << solver.getMinFriendlyColoring(b2) << endl; // 0

    vector<string> b3 = {"....R..........",
                         ".R...........R.",
                         "....R..........",
                         ".R........R....",
                         "....R..........",
                         "....R.....R...."}; 
    cout << solver.getMinFriendlyColoring(b3) << endl; // 1

    vector<string> b4 = {"R.........R",
                         ".R.......R.",
                         "..R.....R..",
                         "...R...R...",
                         "....R.R....",
                         ".....R.....",
                         "....R.R....",
                         "...R...R...",
                         "..R.....R..",
                         ".R.......R.",
                         "R.........R"}; 
    cout << solver.getMinFriendlyColoring(b4) << endl; // 6
}
