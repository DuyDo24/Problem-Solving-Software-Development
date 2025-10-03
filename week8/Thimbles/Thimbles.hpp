#include <vector>
#include <string>

using namespace std;

class Thimbles{
public:
    int thimbleWithBall(vector<string> swaps){
        int current = 1;
        for (string &c : swaps){
            int x = c[0] - '0';
            int y = c[2] - '0';
            if (x == current) current = y;
            else if (y == current) current = x;
        }
        return current;
    }
};