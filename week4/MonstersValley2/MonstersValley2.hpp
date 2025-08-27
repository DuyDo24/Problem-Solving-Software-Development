#include <vector>
#include <algorithm>
using namespace std;

class MonstersValley2{
public:
    int n;
    vector<long long> dread;
    vector<int> price;
    int best;

    void helper(int i, long long currentdread, int gold){
        if (i == n){
            best = min(best, gold);
            return;
        }
      
        helper(i+1, currentdread + dread[i], gold + price[i]);
        
        if (currentdread >= dread[i]){
            helper(i + 1, currentdread, gold);
        }
    }

    int minimumPrice(vector<long long> dread, vector<int> price){
        this->dread = dread;
        this->price = price;
        this->n = dread.size();
        int best = INT_MAX;

        helper(0,0,0);
        return best;
    }
};