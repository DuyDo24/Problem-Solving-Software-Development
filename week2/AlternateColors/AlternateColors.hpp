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
        
        int colors_left = 0;
        if (r > 0) colors_left++;
        if (g > 0) colors_left++;
        if (b > 0) colors_left++;
        
        if (colors_left == 2) {
            // Two colors remaining - they alternate
            if (r == 0) {
                // Only green and blue left, pattern: GREEN, BLUE, GREEN, BLUE...
                if ((k - 1) % 2 == 0) return "GREEN";
                return "BLUE";
            } else if (g == 0) {
                // Only red and blue left, pattern: RED, BLUE, RED, BLUE...
                if ((k - 1) % 2 == 0) return "RED";
                return "BLUE";
            } else {
                // Only red and green left, pattern: RED, GREEN, RED, GREEN...
                if ((k - 1) % 2 == 0) return "RED";
                return "GREEN";
            }
        } else {
            // Only one color remaining
            if (r > 0) return "RED";
            if (g > 0) return "GREEN";
            return "BLUE";
        }
    }
};