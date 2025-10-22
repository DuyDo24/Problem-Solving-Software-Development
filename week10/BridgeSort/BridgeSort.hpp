#include <utility>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class BridgeSort {
public:
    string sortedHand(string hand) {
        vector<pair<char, char>> cards;

        for (int i = 0; i < (int)hand.size(); i += 2) {
            cards.push_back({hand[i], hand[i + 1]});
        }

        string suit = "CDHS";
        string value = "23456789TJQKA";

        auto suitRank = [&](char s) {
            return suit.find(s);
        };
        auto valueRank = [&](char v) {
            return value.find(v);
        };

        sort(cards.begin(), cards.end(), [&](auto &a, auto &b) {
            if (a.first != b.first)
                return suitRank(a.first) < suitRank(b.first);
            return valueRank(a.second) < valueRank(b.second);
        });


        string result;
        for (auto &c : cards) {
            result += c.first;
            result += c.second;
        }
        return result;
    }
};
