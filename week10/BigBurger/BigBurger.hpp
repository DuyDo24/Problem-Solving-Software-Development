#include <vector>
#include <algorithm>
using namespace std;

class BigBurger{
public:
    int maxWait(vector<int> arrival, vector<int> service){
        int maxtime = 0;
        int n = arrival.size();
        int current = 0;
        for (int i = 0;i< n ;i++){
            if (current < arrival[i])
                current = arrival[i];

            int wait = current - arrival[i];  
            maxtime = max(maxtime, wait);

            current += service[i];  
        }
        return maxtime;
    }
};