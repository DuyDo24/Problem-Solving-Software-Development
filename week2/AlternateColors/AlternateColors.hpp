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
        
        while (k > 0) {
            if (r > 0 && k == 1) return "RED";
            if (r > 0) { r--; k--; }
            
            if (g > 0 && k == 1) return "GREEN";
            if (g > 0) { g--; k--; }
            
            if (b > 0 && k == 1) return "BLUE";
            if (b > 0) { b--; k--; }
        }

        return ""; 
    }
};