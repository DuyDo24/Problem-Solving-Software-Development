#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class VeryInterestingMovie{
public:
    int maximumPupils (vector<string> seats){
        int total = 0;
        for (string &row : seats){
            total += helper(row);
        }

        return total;
    }

    int helper(string row){
        int n = row.size();
        vector<int> dp(n,0);

        dp[0] = (row[0] == 'Y' ? 1 : 0);
        dp[1] = max(dp[0], (row[1] == 'Y' ? 1 : 0));

        for (int i = 2; i < n;i++){
            if (row[i] == 'Y'){
                dp[i] = max(dp[i-1], dp[i-2] + 1);
            } else{
                dp[i] = max(dp[i-1], dp[i-2]);
            }
        }
        return dp[n-1];
    }
};