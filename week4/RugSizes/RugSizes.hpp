#include <cmath>
using namespace std;
class RugSizes{
public:
    int rugCount(int area){
        int count = 0;
        int sqrtarea = sqrt(area) + 1 ;
        for (int i = 1;i < sqrtarea;i++){
            for (int j = 1;j < sqrtarea;j++){
                if (i * j == area ){
                    if (i % 2 == 0 && j % 2 == 0 && i != j){
                           continue;
                    } else {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};