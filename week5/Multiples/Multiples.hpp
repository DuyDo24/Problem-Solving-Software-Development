class Multiples{
public:
    int number(int min, int max, int factor){
        int high = max/factor;

        int low;
        if (min < 0) {
            low = min/factor;
            if (min % factor == 0 ){low--;}
        } else {
            low = (min + (factor-1))/factor;
        }
        
        return high - low + 1;
    }
};