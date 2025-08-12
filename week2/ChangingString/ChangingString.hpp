#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class ChangingString{
public:
    int distance(string A, string B, int K){
        int size = A.size();
        vector<int> diff(size);

        for (int i = 0; i < size; i++){
            diff[i] = abs(A[i] - B[i]);
        }
        //sort from descneding order
        sort(diff.begin(), diff.end(), greater<int>());

        int changes = K;
        for (int i = 0; i < size && changes > 0; i++){
            if (diff[i] > 0){
                diff[i] = 0;
                changes--;
            }
        }

        // if we still have changes left, apply to smallest distances
        for (int i = size - 1; i >= 0 && changes > 0; i--){
            if (diff[i] == 0){
                diff[i] = 1; 
                changes--;
            }
        }

        int result = 0;
        for (int d : diff){
            result += d;
        }
        return result;
    }
};