#include <algorithm>
#include <vector>
using namespace std;

class ImportantTasks{
public:
    int maximalCost(vector<int> complexity, vector<int> computers){
        sort(computers.begin(), computers.end());
        sort(complexity.begin(), complexity.end());

        int count = 0;
        for ( int i = 0;i < computers.size(); i++){
            if (computers[i] > complexity[i]){
                count++;
            }
        }
        return count;
    }
};