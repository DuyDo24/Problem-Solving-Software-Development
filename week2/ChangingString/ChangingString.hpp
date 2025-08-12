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

        //find K biggest elements in diff
        for (int i = 0; i < K; i++){
            diff[i] = 0;
        }

        int result = 0;
        for (int d : diff){
            result += d;
        }
        return result;
    }
};