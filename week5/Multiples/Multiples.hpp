#include <cmath>
using namespace std;
class Multiples {
public:
   int number(int min, int max, int factor) {
        int high = max / factor;  
        int low = (int)floor((double)(min - 1) / factor);
        return high - low;
    }
};
