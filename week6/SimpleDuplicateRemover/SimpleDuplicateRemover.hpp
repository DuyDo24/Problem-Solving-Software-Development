#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class SimpleDuplicateRemover{
public:
    vector<int> process(vector<int> sequence){
        unordered_set <int> set;
        int n = sequence.size();
        for (int i = n; i > 0; i--){
            if (set.find(sequence[i]) == set.end()){
                sequence.erase(sequence.begin() + i);
            } else {
                set.insert(sequence[i]);
            }
        }
        reverse(sequence.begin(), sequence.end());
        return sequence;
    }
};