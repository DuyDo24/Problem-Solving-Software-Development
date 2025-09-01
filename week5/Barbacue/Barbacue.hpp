#include <vector>
#include <algorithm>
using namespace std;

class Barbacue{
public:
    int eliminate(int n, vector<int> voter, vector<int> excluded){
        vector<int> votesAginst(n, 0);
        vector<int> votesGiven(n,0);

        for (int i = 0; i < voter.size();i++){
            votesAginst[excluded[i]]++;
            votesGiven[voter[i]]++;
        }
        int result = 0;
        for (int i = 0; i < n; i++){
            if (votesAginst[i] > votesAginst[result]){
                result = i;
            } 
            else if (votesAginst[i] == votesAginst[result]){
                if (votesGiven[i] > votesGiven[result]){
                    result = i;
                } else if (votesGiven[i] == votesGiven[result]){
                    if (i < result){
                        result = i;
                    }
                }
            }
        }
        return result;
    }
};