#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class SimpleDuplicateRemover {
public:
    vector<int> process(vector<int> sequence) {
        unordered_set<int> seen;
        vector<int> result;

        for (int i = (int)sequence.size() - 1; i >= 0; i--) {
            if (seen.find(sequence[i]) == seen.end()) {
                seen.insert(sequence[i]);
                result.push_back(sequence[i]);
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
