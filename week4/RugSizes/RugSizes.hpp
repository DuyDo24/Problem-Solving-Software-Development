#include <cmath>
using namespace std;
class RugSizes{
public:
    int rugCount(int area){
        int count = 0;
        int sqrtarea = sqrt(area) ;
        for (int i = 0;i < sqrtarea;i++){
            for (int j = 0;j < sqrtarea;j++){
                if (i * j == area ){
                    if (i % 2 == 0 && j % 2 == 0 && i != j){
                           count++;
                    }

                }
            }
        }
        return count;
    }
};