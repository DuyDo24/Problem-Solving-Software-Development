#include <string>
#include <algorithm>
using namespace std;

class AlternateColors {
public:
    string getColor(long r, long g, long b, long k) {
        long minimum = min({r, g, b});
        
        if (k <= minimum * 3) {
            long remainder = (k - 1) % 3;
            if (remainder == 0) return "RED";
            if (remainder == 1) return "GREEN";
            return "BLUE";
        } 
        k -= minimum * 3;  
        r -= minimum;     
        g -= minimum;      
        b -= minimum;  

        if (r > 0 && g > 0) {
            if (k % 2 == 1) return "RED";
            return "GREEN";
        }

        if (r > 0 && b > 0) {
            if (k % 2 == 1) return "RED";
            return "BLUE";
        }

        if (g > 0 && b > 0) {
            if (k % 2 == 1) return "GREEN";
            return "BLUE";
        }

        if (r > 0) {
            return "RED";
        }

        if (g > 0) {
            return "GREEN";
        }
  
        return "BAKAAAAA";
    }
};