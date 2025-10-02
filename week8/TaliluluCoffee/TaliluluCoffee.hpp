#include <vector>
#include <algorithm>
using namespace std;

class TaliluluCoffee {
public:
    int maxTip(vector<int> tips) {
        sort(tips.begin(), tips.end(), greater<int>());
        
        int total = 0;
        for (int i = 0;i < tips.size();i++){
            int tip = tips[i] - i;
            if (tip > 0) total += tip;
        }
    return total;
    }
};