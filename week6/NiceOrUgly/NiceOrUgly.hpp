#include <string>
#include <vector>
using namespace std;

class NiceOrUgly {
public:
    string describe(string s) {
        int n = s.size();
        dp.assign(n + 1, vector<vector<int>>(4, vector<int>(6, -1)));

        bool ugly = false, nice = false;
        dfs(0, 0, 0, s, ugly, nice);

        if (ugly && nice) return "42";
        if (ugly) return "UGLY";
        return "NICE";
    }

private:
    vector<vector<vector<int>>> dp;

    void dfs(int i, int v, int c, const string &s, bool &ugly, bool &nice) {
        int n = s.size();
        if (ugly && nice) return;

        if (v == 3 || c == 5) {
            ugly = true;
            return;
        }
        if (i == n) {
            nice = true;
            return;
        }

        if (dp[i][v][c] != -1) {
            int state = dp[i][v][c];
            if (state & 1) ugly = true;
            if (state & 2) nice = true;
            return;
        }

        bool localUgly = false, localNice = false;
        char ch = s[i];

        if (ch == '?') {
            dfs(i + 1, v + 1, 0, s, localUgly, localNice);
            dfs(i + 1, 0, c + 1, s, localUgly, localNice);
        } else if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            dfs(i + 1, v + 1, 0, s, localUgly, localNice);
        } else {
            dfs(i + 1, 0, c + 1, s, localUgly, localNice);
        }

        dp[i][v][c] = (localUgly ? 1 : 0) | (localNice ? 2 : 0);

        if (localUgly) ugly = true;
        if (localNice) nice = true;
    }
};
