#include <vector>
#include <algorithm>
using namespace std;

class CircularLine {
public:
    int longestTravel(vector<int> t){
        int n = t.size();
        int totalsum = 0;
        for (int i = 0; i < n; i ++){
            totalsum += t[i];
        }
        int longest = 0;
        for (int i = 0; i < n; i++){
            int sum = 0;
            for (int j = 1; j < n; j++){
                int next = (i + j - 1) % n;
                sum += t[next];
                int minimum = min(sum, totalsum - sum);
                longest = max(minimum,longest);
            }
        }
        return longest;
    }
};