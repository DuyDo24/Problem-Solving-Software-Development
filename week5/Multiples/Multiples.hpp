class Multiples{
public:
    int number(int min, int max, int factor){
        int high = max/factor;
        int low = min/factor;
        return (high - low) + 1;
    }
};