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
            int score;
            current = arrival[i] + service[i];
            if (i != n){
                int temp = (current - arrival[i+1]);
                score = (temp >= 0) ? temp : 0;
                maxtime = max(maxtime, score );
            }
            if (score == 0){
                current = 0;
            }
        }
    }
};