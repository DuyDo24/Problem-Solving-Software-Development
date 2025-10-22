#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>
using namespace std;

class BlockEnemy {
public:
    int N;
    vector<vector<pair<int,int>>> adj;
    vector<bool> occupied;

    pair<long long,bool> dfs(int u, int parent) {
        bool hasOccupied = occupied[u];
        long long cost = 0;
        vector<int> occupiedEdges;

        for (size_t i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if (v == parent) continue;

            auto sub = dfs(v, u);
            cost += sub.first;
            if (sub.second)
                occupiedEdges.push_back(w);
        }

        if (occupied[u]) hasOccupied = true;

        if (occupiedEdges.size() > 1) {
            sort(occupiedEdges.begin(), occupiedEdges.end());
            for (size_t i = 0; i + 1 < occupiedEdges.size(); ++i)
                cost += occupiedEdges[i];
            hasOccupied = true;
        } else if (occupiedEdges.size() == 1) {
            hasOccupied = true;
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

        return (int)dfs(0, -1).first;
    }
};
