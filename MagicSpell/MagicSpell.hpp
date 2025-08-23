#include <string>
#include <algorithm>
using namespace std;

class MagicSpell{
public:
    string fixTheSpell(string spell){
        int l = 0;
        int r = spell.size() - 1;
        while (l < r) {
            if (!(spell[l] == 'A' || spell[l] == 'Z')) {
                l++;
                continue;
            }
            if (!(spell[r] == 'A' || spell[r] == 'Z')) {
                r--;
                continue;
            }
            // both are A or Z
            swap(spell[l], spell[r]);
            l++;
            r--;
        }
        return spell;
    }
};