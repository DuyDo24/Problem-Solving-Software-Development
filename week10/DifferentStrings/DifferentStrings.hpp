#include <string>
#include <algorithm>
using namespace std;
class DifferentStrings{
public:
    int minimize(string A, string B){
        int diff = INT_MAX;
        int len = B.size() - A.size();

        for (int i = 0 ; i <= len; i++ ){
            int count = 0;
            for (int j = 0; j < A.size();j++){
                 if (A[i] != B[i+j]) count++;
            }
            diff = min(diff,count);
           
        }
        return diff;
    }
};