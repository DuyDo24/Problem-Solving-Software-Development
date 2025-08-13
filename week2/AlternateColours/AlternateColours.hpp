#include <string>
using namespace std;

class AlternateColors {
public:
    string getColor(long long r, long long g, long long b, long long k) {
        long long full_cycles = (k - 1) / 3;
        int pos = (k - 1) % 3;

        // How many balls of each color destroyed in full cycles (cannot exceed total available)
        long long red_destroyed = min(r, full_cycles);
        long long green_destroyed = min(g, full_cycles);
        long long blue_destroyed = min(b, full_cycles);

        // Remaining balls after full cycles
        long long r_rem = r - red_destroyed;
        long long g_rem = g - green_destroyed;
        long long b_rem = b - blue_destroyed;

        // Check the color of the k-th ball depending on position in cycle and availability

        // Position 0: red step
        if (pos == 0) {
            if (r_rem > 0) return "RED";
            else if (g_rem > 0) return "GREEN";
            else return "BLUE";
        }
        // Position 1: green step
        else if (pos == 1) {
            if (g_rem > 0) return "GREEN";
            else if (b_rem > 0) return "BLUE";
            else return "RED";
        }
        // Position 2: blue step
        else { // pos == 2
            if (b_rem > 0) return "BLUE";
            else if (r_rem > 0) return "RED";
            else return "GREEN";
        }
    }
};
