#include <vector>
#include <string>
using namespace std;

class CorporationSalary {
public:
    long totalSalary(vector<string> relations) {
        int n = relations.size();
        vector<long> memo(n, -1);

        long total = 0;
        for (int i = 0; i < n; i++) {
            total += dfs(i, relations, memo);
        }
        return total;
    }

private:
    long dfs(int i, const vector<string>& relations, vector<long>& memo) {
        if (memo[i] != -1) return memo[i];

        long salary = 0;
        bool hasSub = false;
        for (int j = 0; j < (int)relations.size(); j++) {
            if (relations[i][j] == 'Y') {
                hasSub = true;
                salary += dfs(j, relations, memo);
            }
        }

        if (!hasSub) salary = 1;
        return memo[i] = salary;
    }
};
