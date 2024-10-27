/*
1436. Destination City
    You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi. Return the destination city, that is, the city without any path outgoing to another city.
    It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.

    Example :
    Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
    Output: "Sao Paulo" 
    Explanation: Starting at "London" city you will reach "Sao Paulo" city which is the destination city. Your trip consist of: "London" -> "New York" -> "Lima" -> "Sao Paulo".
*/

#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n = paths.size();
        for (int i = 0; i < n; i++){
            string cityB = paths[i][1];
            bool find = false;
            for (int j = 0; j < n; j++){
                if (paths[j][0] == cityB){
                    find = true;
                    break;
                }
            }
            if (!find)
                return cityB;
        }
        return "";
    }
};