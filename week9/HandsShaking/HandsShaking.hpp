#include <vector>
using namespace std;

class HandsShaking {
public:
    long countPerfect(int n) {
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 2; i <= n; i += 2) {
            for (int j = 2; j <= i; j += 2) {
                dp[i] += dp[j - 2] * dp[i - j];
            }
        }
        return dp[n];
    }
};
