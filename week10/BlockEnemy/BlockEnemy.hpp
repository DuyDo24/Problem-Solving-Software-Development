#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

class BlockEnemy {
public:
    int N;
    vector<vector<pair<int,int>>> adj; 
    vector<bool> occupied;

    const int INF_EFFORT = 1000001; 

    pair<long long,bool> dfs(int u, int parent) {
        long long current_cost = 0;
        vector<int> occupied_paths_weights;

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (v == parent) continue;

            auto sub_result = dfs(v, u);
            current_cost += sub_result.first;

            if (sub_result.second) {
                occupied_paths_weights.push_back(w);
            }
        }

        if (occupied[u]) {
            occupied_paths_weights.push_back(INF_EFFORT);
        }

        int k = occupied_paths_weights.size();
        
        if (k > 1) {
            sort(occupied_paths_weights.begin(), occupied_paths_weights.end());

            for (int i = 0; i < k - 1; ++i) {
                current_cost += occupied_paths_weights[i];
            }
            
            return {current_cost, true};

        } else if (k == 1) {
            return {current_cost, true};

        } else {
            return {current_cost, false};
        }
    }

    int minEffort(int N, vector<string> roads, vector<int> occupiedTowns) {
        this->N = N;
        adj.assign(N, {});
        occupied.assign(N, false);

        for (int town : occupiedTowns) {
            occupied[town] = true;
        }

        for (auto &s : roads) {
            stringstream ss(s);
            int a, b, e;
            ss >> a >> b >> e;
            adj[a].push_back({b, e});
            adj[b].push_back({a, e});
        }

        return (int)dfs(0, -1).first;
    }
};