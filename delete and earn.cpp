class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = 0;
        for (int x : nums) maxVal = max(maxVal, x);

        vector<int> count(maxVal + 1, 0);
        for (int x : nums) {
            count[x] += x;  
        }

        vector<int> dp(maxVal + 1, 0);

        dp[0] = 0;
        if (maxVal >= 1) dp[1] = count[1];

        for (int i = 2; i <= maxVal; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + count[i]);
        }

        return dp[maxVal];
    }
};
