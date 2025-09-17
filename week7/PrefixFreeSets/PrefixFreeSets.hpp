#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class PrefixFreeSets {
public:
    int maxElements(vector<string> words) {
        sort(words.begin(), words.end(), [](const string &a, const string &b){
            return a.size() < b.size();
        });

        vector<string> chosen;
        for (string &w : words) {
            bool bad = false;
            for (string &c : chosen) {
                if (w.size() >= c.size() && w.compare(0, c.size(), c) == 0) {
                    bad = true;
                    break;
                }
            }
            if (!bad) chosen.push_back(w);
        }
        return chosen.size();
    }
};
