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

        long long two_color_min = 0;
        if (r == 0) {
            two_color_min = min(g, b);
        } else if (g == 0) {
            two_color_min = min(r, b);
        } else { // b must be 0
            two_color_min = min(r, g);
        }

        if (k <= two_color_min * 2) {
            if (r == 0) { // Sequence is GREEN, BLUE
                if (k % 2 == 1) {
                    return "GREEN";
                } else {
                    return "BLUE";
                }
            }
            if (g == 0) { // Sequence is RED, BLUE
                if (k % 2 == 1) {
                    return "RED";
                } else {
                    return "BLUE";
                }
            }
            // b must be 0, sequence is RED, GREEN
            if (k % 2 == 1) {
                return "RED";
            } else {
                return "GREEN";
            }
        }
        
        // We've passed Phase 2. Update k and the ball counts again.
        k -= two_color_min * 2;
        if (r == 0) {
            g -= two_color_min;
            b -= two_color_min;
        } else if (g == 0) {
            r -= two_color_min;
            b -= two_color_min;
        } else { // b == 0
            r -= two_color_min;
            g -= two_color_min;
        }

        // Phase 3: Only one color remains
        if (r > 0) {
            return "RED";
        }
        if (g > 0) {
            return "GREEN";
        }
        return "BLUE";
    }
};