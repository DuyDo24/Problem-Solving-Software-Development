using namespace std;

class EggCartons{
public:
    int minCartons(int n){
        if (n % 2 != 0){
            return -1;
        }
        int count = 0;
        int total = 0;
        if (n == 10){
            return -1;
        }
        if (n >= 12){
            while (total < n){
                total += 8;
                count++;
            }
        }
        return count;
    }
};