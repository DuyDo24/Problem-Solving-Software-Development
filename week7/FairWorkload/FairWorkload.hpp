#include <vector>
#include <algorithm>

using namespace std;

class FairWorkload{
public:
    int getMostWork(vector<int> folders, int workers){
        int sum = 0;
        for (int x : folders) sum += x;

        auto maxvalue = max_element(folders.begin(), folders.end());
        int max = *maxvalue;

        while (max < sum){
            int mid = (max + sum) / 2;
            if (helper(folders, workers, mid)){
                sum = mid;
            } else{
                max = mid + 1;
            }
        }
        return max;
    }

    bool helper(vector<int>& a, int b, int mid){
        int used = 1;
        int current = 0;

        for (int i = 0; i < a.size();i++){
            if (current + a[i] <= mid){
                current += a[i];
            } else{
                current = a[i];
                used++;
            }
            if (used > b){
                return false;
            }
        }
    return true;
    }
};