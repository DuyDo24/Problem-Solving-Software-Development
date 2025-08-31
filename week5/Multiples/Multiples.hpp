class Multiples {
public:
    int number(int min, int max, int factor) {
        int high = max / factor;
        int low;
        if (min > 0) {
            low = (min - 1) / factor;
        } else {
            low = (min - 1) / factor;
            if ((min - 1) % factor != 0) low--;
        }
        return high - low;
    }
};
