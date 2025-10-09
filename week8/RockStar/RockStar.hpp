#include <algorithm>
using namespace std;

class RockStar{
public:
    int getNumSongs(int ff, int fs, int sf, int ss){
        int total = 0;
        if (ff == 0 && fs == 0){
            if (sf >= 1){
                return ss + 1;
            } 
            return ss;
        }
        total = ff;
        if (fs != 0){
            total++;
            if (sf != 0){         
                fs--;
                total += 2 * min(sf, fs);
            }
            if (fs > 0) {          
                total += ss;
            }
        }
        return total;
    }
};