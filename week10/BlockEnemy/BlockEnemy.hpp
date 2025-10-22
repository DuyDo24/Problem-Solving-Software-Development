#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>
using namespace std;

class BlockEnemy{
public:
    int N;
    vector<vector<pair<int,int>>> adj;
    vector<bool> occupied;

    pair<int,bool> dfs(int u, int parent) {
        bool hasOccupied = occupied[u];
        int cost = 0;

        for (auto [v, w] : adj[u]) {
            if (v == parent) continue;
            auto [subCost, subOccupied] = dfs(v, u);
            cost += subCost;

            if (subOccupied && hasOccupied) {
                cost += w;
            } else {
                hasOccupied = hasOccupied || subOccupied;
            }
        }

        return {cost, hasOccupied};
    }

    int minEffort(int N, vector<string> roads, vector<int> occupiedTowns) {
        this->N = N;
        adj.assign(N, {});
        occupied.assign(N, false);

        for (int town : occupiedTowns)
            occupied[town] = true;

        for (auto &s : roads) {
            stringstream ss(s);
            int a, b, e;
            ss >> a >> b >> e;
            adj[a].push_back({b, e});
            adj[b].push_back({a, e});
        }

        return dfs(0, -1).first;
    }
};
