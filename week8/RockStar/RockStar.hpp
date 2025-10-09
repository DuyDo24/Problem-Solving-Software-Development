#include <algorithm>
using namespace std;

class RockStar {
public:
    int getNumSongs(int ff, int fs, int sf, int ss) {
        if (ff + fs == 0) {
            return ss + (sf > 0 ? 1 : 0);
        }
        int total = ff;
        if (sf == 0) {
            if (fs > 0) total += 1 + ss;
        } else if (fs == 0) {
            total += 0; 
        } else {
            total += 2 * min(fs, sf) + ss;
            if (fs > sf) total += 1;
        }
        return total;
    }
};
