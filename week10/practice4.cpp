#include <vector>
using namespace std;


class IslandNetwork{
public:
    int countConnectedIslands(vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n , vector<bool>(m , false));
        int islands = 0;
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == '1' && !(visited[i][j])){
                   dfs(i , j , grid, visited, n ,m);
                   islands++;
                }
            }
         }
        return islands;
    }


    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited, int n, int m){
        if (i < 0 || j < 0 || i >= n || j >= m) {
            return;
        }
        if (grid[i][j] != '1' || visited[i][j] ){
            return;
        }
        visited[i][j] = true;

        dfs(i + 1, j, grid,visited,n,m);
        dfs(i , j + 1, grid,visited,n,m);
        dfs(i - 1, j , grid,visited,n,m);
        dfs(i, j - 1, grid,visited,n,m);
    }
};