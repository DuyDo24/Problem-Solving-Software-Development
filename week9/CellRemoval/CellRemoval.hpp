#include <vector>

using namespace std;

class CellRemoval{
public:
    int cellsLeft(vector<int> parent, int deletedCell){
        int n = parent.size();
        vector<vector<int>> children(n);
        int root = -1;

        for (int i = 0;i< n;i++){
            if (parent[i] == -1){
                root = i;
            } else{
                children[parent[i]].push_back(i);
            }
        }
        vector<bool> deleted(n, false);
        markDeleted(deletedCell, children, deleted);
        int count = 0;
        for (int i = 0;i < n;i++){
            if (deleted[i]) continue;
            bool isLeaf = true;
            for (int c : children[i]){
                if (!deleted[c]){
                    isLeaf = false;
                    break;
                }
            }
            if (isLeaf) count++;
        }
        return count;

    }
private:
    void markDeleted(int node, vector<vector<int>>& children, vector<bool>& deleted){
        deleted[node] = true;
        for (int c : children[node]){
            markDeleted(c,children,deleted );
        }
    }
};