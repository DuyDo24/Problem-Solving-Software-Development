#include <cmath>
using namespace std;
class RugSizes{
public:
    int rugCount(int area){
        int count = 0;
        for (int i = 1; i * i < area;i++){
            if (area % i != 0) continue;
            int length = area / i;
            if (i % 2 == 0 && length % 2 == 0 && i != length) continue;
            count++;
        }
        return count;
    }
};