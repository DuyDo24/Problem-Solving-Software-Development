#include <string>
using namespace std;

class StrangeComputer{
public:
    int setMemory(string mem){
        int count = 0;
        char num = '0';
        for (int i = 0; i < mem.size(); i++){
            if (mem[i] != num ){
                count++;
                num = mem[i];
            }
        }
        return count;
    }
};