#include <string>
using namespace std;

class QuickSums{
public:
    int best;
    void dfs(const string &numbers, int target, int pos, long long currentSum, int additions) {
        int n = numbers.size();
        if (pos == n) {
            if (currentSum == target) {
                if (additions < best) best = additions;
            }
            return;
        }
        long long val = 0;
        for (int i = pos; i < n; i++) {
            val = val * 10 + (numbers[i] - '0'); 
            dfs(numbers, target, i + 1, currentSum + val, additions + (pos == 0 ? 0 : 1));
        }
    }

    int minSums(string numbers, int sum) {
        best = -1;
        dfs(numbers, sum, 0, 0, 0);
        return best;
    }
};
