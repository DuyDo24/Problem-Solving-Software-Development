#include <string>
using namespace std;

class StreetParking{
public:
    int freeParks(string street){
        int count = 0;
        for (int i = 0; i < street.size(); i++){
            if (street[i] != '-') {
                continue; 
            }
            if (street[i] == 'D' || street[i] == 'B' || street[i] == 'S'){
                continue;
            } 
            if (i - 1 >= 0 && (street[i - 1] == 'B' || street[i - 1] == 'S')) {
                continue;
            }
            if (i - 2 >= 0 && street[i - 2] == 'B') {
                continue;
            }
            if (i + 1 < street.size() && street[i + 1] == 'S') {
                continue;
            }
            count++;
        }
        return count;
    }
};
