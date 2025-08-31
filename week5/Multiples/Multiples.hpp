class Multiples{
public:
    int number(int min, int max, int factor){
        int high = max/factor;
        int low = (min + (factor-1))/factor;
        return (high - low) + 1;
    }
};