#include <string>
#include <vector>
using namespace std;

class NiceOrUgly{
public:
    string describe(string s){
        bool ugly = false;
        bool nice = false;
        dfs(0,0,0,s,ugly,nice);

        if (ugly && nice)return "42";
        if (ugly) return "UGLY";

        return "NICE";
    }

    void dfs(int i, int v, int c, const string& s, bool &ugly, bool &nice){
        int n = s.size();
        if (ugly && nice){
            return;
        }
        if (v == 3 || c == 5){
            ugly = true;
            return;
        }
        if (i == n){
            nice = true;
            return;
        }
        char ch = s[i];
        if (ch == '?'){
            dfs(i + 1, v + 1, 0, s, ugly, nice);
            dfs(i + 1, 0, c + 1, s, ugly, nice);

        } else if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch =='U'){
            dfs(i + 1, v + 1, 0, s, ugly, nice);
        } else {
            dfs(i + 1, 0, c+1, s, ugly, nice);
        }
    }
};