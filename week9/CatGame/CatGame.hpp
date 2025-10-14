#include <vector>
#include <algorithm>
using namespace std;

class CatGame {
public:
    int getNumber(vector<int> coordinates, int X) {
        sort(coordinates.begin(), coordinates.end());
        int n = coordinates.size();
        if (n == 1) return 0;

        int ans = coordinates.back() - coordinates.front() + 2 * X; 
        
        for (int i = 0; i < n - 1; ++i) {
            int leftmost = min(coordinates.front() + X, coordinates[i + 1] - X);
            int rightmost = max(coordinates[i] + X, coordinates.back() - X);
            ans = min(ans, rightmost - leftmost);
        }

        return ans;
    }
};
