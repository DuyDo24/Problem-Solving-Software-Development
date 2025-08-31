class Multiples {
public:
    int number(int min, int max, int factor) {
        int start = min;
        if (min % factor != 0) {
            start += factor - (min % factor);
        }
        int end = max - (max % factor);
        if (start > max) return 0;
        return (end - start) / factor + 1;
    }
};
