class Multiples {
public:
    int number(int min, int max, int factor) {
        int firstMultiple;
        if (min >= 0) {
            firstMultiple = ((min + factor - 1) / factor) * factor;
        } else {
            firstMultiple = (min / factor) * factor;
        }
        
        int lastMultiple = (max / factor) * factor;
        
        return (lastMultiple - firstMultiple) / factor + 1;
    }
};