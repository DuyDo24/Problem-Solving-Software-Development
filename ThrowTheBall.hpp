#include <vector>
using namespace std;

class ThrowTheBall {
public:
    int timesThrown(int N, int M, int L){
        vector<int> received(N, 0);
        int current = 0;
        received[current] = 1;
        int count = 0;

        while (received[current] != M){
            if (received[current] % 2 == 1) {
            current = (current + L) % N;
        } else {
            current = (current - L + N) % N;
        }
        received[current]++;
        count++;

        }
     return count;
    }
};
