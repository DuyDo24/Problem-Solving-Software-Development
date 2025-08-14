using namespace std;

class EggCartons {
public:
    int minCartons(int n) {
        if (n % 2 != 0 || n == 10) return -1;
        if (n == 6 || n == 8) return 1;
        if (n >= 12) {
            int count = n / 8;
            if (n % 8 != 0) count++;
            return count;
        }
        return -1;
    }
};
