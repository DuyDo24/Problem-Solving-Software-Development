#include <string>
#include <algorithm>
using namespace std;

class MagicSpell{
public:
    string fixTheSpell(string spell){
        int l = 0;
        int r = spell.size();
        while (l < r){
            if (spell[l] == 'A' || spell[l] == 'Z' && spell[r] == 'A' || spell[r] == 'Z'){
                swap(spell[l],spell[r]);
            }
            if (spell[l] != 'A' || spell[l] != 'Z'){
                l++;
            }
            if (spell[r] != 'A' || spell[r] != 'Z'){
                r--;
            }
        }
        return spell;
    }
};