class Multiples {
public:
    int number(int min, int max, int factor) {
        return (max / factor) - ((min - 1) / factor);
    }
};