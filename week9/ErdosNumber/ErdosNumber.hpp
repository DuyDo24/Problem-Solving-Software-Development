#include <vector>
#include <algorithm>
#include <unordered_map>
#include <sstream>
#include <unordered_set>
#include <queue>

using namespace std;

class ErdosNumber {
public:
    vector<string> calculateNumbers(vector<string> publications) {
        unordered_map<string, vector<string>> graph;
        unordered_set<string> allAuthors;

        for (string pub : publications) {
            stringstream ss(pub);
            vector<string> authors;
            string author;
            while (ss >> author) {
                authors.push_back(author);
                allAuthors.insert(author);
            }
            for (int i = 0; i < (int)authors.size(); i++) {
                for (int j = i + 1; j < (int)authors.size(); j++) {
                    graph[authors[i]].push_back(authors[j]);
                    graph[authors[j]].push_back(authors[i]);
                }
            }
        }
        unordered_map<string, int> dist;
        queue<string> q;

        if (allAuthors.count("ERDOS")) {
            dist["ERDOS"] = 0;
            q.push("ERDOS");
        }

        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            int d = dist[curr];
            for (auto &neighbor : graph[curr]) {
                if (!dist.count(neighbor)) {
                    dist[neighbor] = d + 1;
                    q.push(neighbor);
                }
            }
        }

        vector<string> result;
        vector<string> authorsList(allAuthors.begin(), allAuthors.end());
        sort(authorsList.begin(), authorsList.end());

        for (auto &a : authorsList) {
            if (dist.count(a))
                result.push_back(a + " " + to_string(dist[a]));
            else
                result.push_back(a);
        }

        return result;
    }
};
