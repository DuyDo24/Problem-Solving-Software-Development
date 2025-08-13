#include <string>
#include <vector>
using namespace std;

class SquareOfDigits{
public:
    int getMax(vector<string> data){
        int rows = data.size();
        int cols = data[0].size();
        int maxside = min(rows, cols);

        for (int side = maxside; side >= 1; side--) {
            for (int r = 0; r + side <= rows; r++) {
                for (int c = 0; c + side <= cols; c++) {
                    char corner = data[r][c];
                    if (data[r][c + side - 1] == corner &&
                        data[r + side - 1][c] == corner &&
                        data[r + side - 1][c + side - 1] == corner) {
                        return side * side; 
                    }
                }
            }
        }
        return 1;

    }
};