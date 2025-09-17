#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class PrefixFreeSets {
public:
    int maxElements(vector<string> words) {
        sort(words.begin(), words.end());

        int n = words.size();
        vector<bool> used(n, true);

        for (int i = 0; i < n - 1; i++) {
            if (isPrefix(words[i], words[i+1])) {
                used[i] = false; 
            }
        }

        int count = 0;
        for (bool u : used) if (u) count++;
        return count;
    }

private:
    bool isPrefix(const string &a, const string &b) {
        if (a.size() > b.size()) return false;
        return b.compare(0, a.size(), a) == 0;
    }
};
