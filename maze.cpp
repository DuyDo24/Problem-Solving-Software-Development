class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;

        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        q.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]] = true;

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [i, j] = q.front();
                q.pop();

                // Check exit (but not the entrance)
                if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) &&
                    !(i == entrance[0] && j == entrance[1])) {
                    return steps;
                }

                for (auto& d : dirs) {
                    int ni = i + d[0];
                    int nj = j + d[1];

                    if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
                        !visited[ni][nj] && maze[ni][nj] == '.') {
                        visited[ni][nj] = true;
                        q.push({ni, nj});
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};
