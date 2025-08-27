#include <vector>
using namespace std;

class UnsealTheSafe {
public:
    long countPasswords(int N) {
        vector<vector<int>> adj = {
            {7},          
            {2, 4},       
            {1, 3, 5},    
            {2, 6},       
            {1, 5, 7},    
            {2, 4, 6, 8}, 
            {3, 5, 9},    
            {4, 8, 0},   
            {5, 7, 9},    
            {6, 8}        
        };

        vector<vector<long>> dp(N + 1, vector<long>(10, 0));
        
        for (int d = 0; d < 10; d++) dp[1][d] = 1;

        for (int len = 2; len <= N; len++) {
            for (int d = 0; d < 10; d++) {
                for (int prev : adj[d]) {
                    dp[len][d] += dp[len-1][prev];
                }
            }
        }

        long total = 0;
        for (int d = 0; d < 10; d++) total += dp[N][d];
        return total;
    }
};
