class Inchworm {
public:
    int lunchtime(int branch, int rest, int leaf) {
        int count = 0;
        for (int i = 0; i <= branch; i += rest) {
            if (i % leaf == 0)
                count++;
        }
        return count;
    }
};

