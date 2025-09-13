#include <string>
#include <cmath>
#include <climits>
using namespace std;

class MinimalDifference{
public:
    int findNumber(int A, int B, int C){
        int csum = helper(C);
        int closest = A;
        int close = 1e9;

        for (int i = A; i <= B; i++){
            int temp = helper(i);
            int diff = abs(temp - csum);

            if (temp == csum){
                return i;
            } 
            if (diff < close){
                close = diff;
                closest = i;
            }
        }
    return closest;
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