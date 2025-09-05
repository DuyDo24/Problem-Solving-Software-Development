#include <algorithm>
#include <vector>
using namespace std;

class ImportantTasks{
public:
    int maximalCost(vector<int> complexity, vector<int> computers){
        sort(computers.rbegin(), computers.rend());
        sort(complexity.rbegin(), complexity.rend());

        int count = 0;
        int complex = 0;
        int comput = 0;

        while (complex < complexity.size() && comput < computers.size()){
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