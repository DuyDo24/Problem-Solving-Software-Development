class Multiples{
public:
    int number(int min, int max, int factor){
        int high;
        if (high < 0){
            high = (max + (factor-1) /factor);
        } else {
            high = max / factor;
        }

        int low;
        if (min < 0) {
            low = min/factor;
        } else {
            low = (min + (factor-1))/factor;
        }
        
        return high - low + 1;
    }
};