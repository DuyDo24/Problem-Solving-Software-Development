#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class MooingCows {
public:
    int dissatisfaction(vector<string> farmland) {
        int n = farmland.size();
        int m = farmland[0].size();
        vector<pair<int,int>> cows;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (farmland[i][j] == 'C') cows.push_back({i,j});
            }
        }

        int minDissatisfaction = 10000;

        for (auto &mooCow : cows) {
            int total = 0;
            for (auto &otherCow : cows) {
                if (mooCow != otherCow) {
                    int dx = mooCow.first - otherCow.first;
                    int dy = mooCow.second - otherCow.second;
                    total += dx*dx + dy*dy;
                }
            }
            minDissatisfaction = min(minDissatisfaction, total);
        }

        return minDissatisfaction;
    }
};
