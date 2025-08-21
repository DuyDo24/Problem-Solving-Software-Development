#include <string>
using namespace std;

class StrangeComputer{
public:
    int setMemory(string mem){
        int count = 0;
        bool num = false;
        for (int i = 0; i < mem.size(); i++){
            if (mem[i] != num ){
                count++;
                if (num == true){
                    num == false;
                } else {
                    num == true;
                }
            }
        }
        return count;
    }
};