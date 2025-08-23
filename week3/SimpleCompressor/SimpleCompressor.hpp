#include <string>
using namespace std;

class SimpleCompressor {
public:
    string helper(const string& data, int &pos) {
        string result = "";
        while (pos < data.size() && data[pos] != ']') {
            if (isalpha(data[pos])) {
                result.push_back(data[pos]);
                pos++;
            } else if (data[pos] == '[') {
                pos++;
                int D = data[pos] - '0';
                pos++; 
                string inside = helper(data, pos);
                for (int i = 0; i < D; i++){
                    result += inside;
                }
            } else{
                pos++;
            }
        }
        return result;
    }

    string uncompress(string data) {
        int pos = 0;
        return helper(data, pos);
    }
};
