#include <cmath>
using namespace std;

class Multiples {
public:
    int number(int min, int max, int factor) {
        int maxDiv = (int)floor((double)max / factor);
        int minDiv = (int)floor((double)(min - 1) / factor);
        
        return maxDiv - minDiv;
    }
};