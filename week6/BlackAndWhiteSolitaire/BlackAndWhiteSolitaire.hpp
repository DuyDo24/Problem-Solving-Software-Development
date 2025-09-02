#include <string>
#include <algorithm>
using namespace std;

class BlackAndWhiteSolitaire{
public:
    int minimumTurns(string cardFront){
        int n = cardFront.size();
        string B;
        string W;

        for (int i = 0; i < n ; i++){
            if (i % 2 == 0){
                B.push_back('B');
                W.push_back('W');
            } else {
                B.push_back('W');
                W.push_back('B');
            }
        }
        int countB = 0;
        int countW = 0;
        for (int i = 0; i < n; i++){
            if (cardFront[i] != B[i]){
                countB++;
            }
            if (cardFront[i] != W[i]){
                countW++;
            }
        }
        return min(countB,countW);
    }
};