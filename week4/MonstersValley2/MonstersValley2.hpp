#include <vector>
#include <algorithm>
using namespace std;

class MonstersValley2{
public:
    int n;
    vector<int> dread;
    vector<int> price;
    int best;

    void helper(int i, int currentdread, int gold){
        if (i == n){
            best = min(best, gold);
            return;
        }
      
        helper(i+1, currentdread + dread[i], gold + price[i]);
        
        if (currentdread >= dread[i]){
            helper(i + 1, currentdread, gold);
        }
    }

    int minimumPrice(vector<int> dread, vector<int> price){
        this->dread = dread;
        this->price = price;
        this->n = dread.size();
        int best = 1e9;

        helper(0,0,0);
        return best;
    }
};