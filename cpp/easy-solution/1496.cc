/*
1496. Path Crossing
    Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.
    Return true if the path crosses itself at any point, that is, if at any time you are on a location you have previously visited. Return false otherwise.

    Example :
    Input: path = "NES"
    Output: false 
    Explanation: Notice that the path doesn't cross any point more than once.
*/

#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0, y = 0;
        set<vector<int>> xoy;
        xoy.insert({0, 0});
        for (char i : path){
            if (i == 'N'){
                y++;
            }
            else if ( i == 'E'){
                x++;
            }
            else if ( i == 'S'){
                y--;
            }
            else{
                x--;
            }
            if (xoy.find({x, y}) != xoy.end()){
                return true;
            }
            xoy.insert({x, y});
        }
        return false;
    }
};