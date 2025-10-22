#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>

using namespace std;

struct Road {
    int u, v, effort;
};

class DSU {
private:
    vector<int> parent;
    vector<bool> isOccupiedComponent; 

public:
    DSU(int n, const vector<int>& occupiedTowns) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0); 
        isOccupiedComponent.resize(n, false);

        for (int town : occupiedTowns) {
            isOccupiedComponent[town] = true;
        }
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    bool unite(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);

        if (root_u != root_v) {
            bool status_u = isOccupiedComponent[root_u];
            bool status_v = isOccupiedComponent[root_v];

            if (status_u && status_v) {
                return false; 
            }

            parent[root_v] = root_u; 
            isOccupiedComponent[root_u] = status_u || status_v;
            return true; 
        }
        return true; 
    }
};

class BlockEnemy {
public:
    int minEffort(int N, vector<string> roads, vector<int> occupiedTowns) {
        if (occupiedTowns.size() <= 1) {
            return 0;
        }

        vector<Road> roadList;
        long long totalEffort = 0;

        for (const string& roadStr : roads) {
            stringstream ss(roadStr);
            int u, v, e;
            ss >> u >> v >> e;
            roadList.push_back({u, v, e});
            totalEffort += e;
        }

        sort(roadList.begin(), roadList.end(), [](const Road& a, const Road& b) {
            return a.effort > b.effort;
        });

        DSU dsu(N, occupiedTowns);
        long long keptEffort = 0;

        for (const auto& road : roadList) {
            if (dsu.unite(road.u, road.v)) {
                keptEffort += road.effort;
            }
        }

        return (int)(totalEffort - keptEffort);
    }
};