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

         if (r > 0 && g > 0 && b == 0) {
            // After R-G-B cycles, next would be R, so: R-G-R-G...
            if (k % 2 == 1) return "RED";
            return "GREEN";
        }
        
        if (r > 0 && b > 0 && g == 0) {
            // After R-G-B cycles, if we ran out of G, we were at position "G"
            // So next should be B, then R: B-R-B-R...
            if (k % 2 == 1) return "BLUE";
            return "RED";
        }
        
        if (g > 0 && b > 0 && r == 0) {
            // After R-G-B cycles, if we ran out of R, we were at position "R"  
            // So next should be G: G-B-G-B...
            if (k % 2 == 1) return "GREEN";
            return "BLUE";
        }
        
        // Phase 3: Only one color remains
        if (r > 0) return "RED";
        if (g > 0) return "GREEN";
        return "BLUE";
    }
};