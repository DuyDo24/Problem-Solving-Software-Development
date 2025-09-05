#include <algorithm>
#include <vector>
using namespace std;

class ImportantTasks{
public:
    int maximalCost(vector<int> complexity, vector<int> computers){
        sort(computers.begin(), computers.end());
        sort(complexity.begin(), complexity.end());

        int count = 0;
        int complex = 0;
        int comput = 0;

        while (complex < computers.size()){
            if (computers[comput] >= complexity[complex]){
                count++;
                comput++;
                complex++;
            } else {
                complex++;
            }
        }
        return count;
    }
};