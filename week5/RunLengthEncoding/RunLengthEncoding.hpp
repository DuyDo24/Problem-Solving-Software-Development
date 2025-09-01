#include <string>
#include <cctype>
using namespace std;

class RunLengthEncoding {
public:
    string decode(string text) {
        string result = "";
        int i = 0;
        while (i < text.size()) {
            int number = 0;
            while (i < text.size() && isdigit(text[i])) {
                number = number * 10 + (text[i] - '0');
                i++;
            }
            if (number == 0) {
                number = 1;
            }
            for (int j = 0; j < number; j++) {
                result += text[i];
                if (result.size() > 50) {
                    return "TOO LONG";
                }
            }
            i++;
        }
        return result;
    }
};
