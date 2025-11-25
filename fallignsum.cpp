class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for (int i = n-2 ;i >= 0; i--){
            for (int j = 0; j < n; j++){
                int best = matrix[i+1][j];

                if (j > 0){
                    best = min(best, matrix[i+1][j-1]);
                }
                if (j < n-1){
                    best = min(best, matrix[i+1][j+1]);
                }
                matrix[i][j] += best;
            }
        }
        int temp = INT_MAX;
        for (int i = 0; i < n;i ++){
            temp = min(temp,matrix[0][i]);
        }
        return temp;
    }
};