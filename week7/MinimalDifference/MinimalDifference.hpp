#include <string>
using namespace std;

class MinimalDifference{
public:
    int findNumber(int A, int B, int C){
        int csum = helper(C);
        int closest = 0;
        int close = 10e9;

        for (int i = A; i < B; i++){
            int temp = helper(i);
            if (temp == csum){
                return i;
            } 
        }
    return A;
    }
private:
    int helper(int n){
        string temp = to_string(n);
        int result = 0;
        for(char c : temp){
            result += (c - '0');
        }
    return result;
    }
};