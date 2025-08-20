#include <string>
#include <algorithm>
using namespace std;

class Arrows{
public:
    int longestArrow(string s){
        int maxlength = -1;
        for (int i = 0;i < s.size(); i++){
            if (s[i] == '<' ){
                int len = 1;
                int j = i + 1;
                while (j < s.size() && s[j] == '-' ){
                    len++;
                    j++;
                }
                maxlength = max(len, maxlength);

                len = 1;
                j = i + 1;

                while (j < s.size() && s[j] == '=' ){
                    len++;
                    j++;
                }
                maxlength = max(len, maxlength);
            }
            if (s[i] == '>'){
                int len = 1;
                int j = j - 1;
                while (j > 0 && s[j] == '-'){
                    j--;
                    len++;
                }
                maxlength = max(len, maxlength);

                len = 1;
                j = j - 1;
                while (j > 0 && s[j] == '='){
                    j--;
                    len++;
                }
                maxlength = max(len, maxlength);
            }
        }
        return maxlength;
    }
};