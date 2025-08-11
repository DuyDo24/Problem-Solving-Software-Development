#include <string>
#include <vector>
using namespace std;

class AzimuthMonitoring{
public:
    int getAzimuth(vector<string> instructions){
        int size = instructions.size();
        int azimuth = 0;

        for (int i = 0; i < size; i++){
            string word = instructions[i];
            if (word == "HALT"){
                break;
            }
            else if (word == "RIGHT"){
                azimuth += 90;
            }
            else if (word == "LEFT"){
                azimuth -= 90;
            }
            else if (word == "TURN AROUND"){
                azimuth += 180;
            }
            else if(word.substr(0, 4) == "LEFT"){
                int degrees = stoi(word.substr(5));
                azimuth -= degrees;
            }
            else if(word.substr(0, 5) == "RIGHT"){
                int degrees = stoi(word.substr(6));
                azimuth += degrees;
            }
        }
        azimuth = ((azimuth % 360) + 360) % 360;
        return azimuth;
    }
};