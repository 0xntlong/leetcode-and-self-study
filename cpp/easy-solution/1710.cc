/*
1710. Maximum Units on a Truck
    You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:
    numberOfBoxesi is the number of boxes of type i.
    numberOfUnitsPerBoxi is the number of units in each box of the type i.
    You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.
    Return the maximum total number of units that can be put on the truck.

    Example :
    Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
    Output: 8
    Explanation: There are:
    - 1 box of the first type that contains 3 units.
    - 2 boxes of the second type that contain 2 units each.
    - 3 boxes of the third type that contain 1 unit each.
    You can take all the boxes of the first and second types, and one box of the third type.
    The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b){
            return a[1] > b[1];
        });
        int totalUnits = 0, size = 0, i = 0;
        for (int i = 0; i < boxTypes.size() && size < truckSize; i++){
            if ( size + boxTypes[i][0] > truckSize){
                totalUnits += boxTypes[i][1] * (truckSize - size);
                break;
            } else {
                totalUnits += boxTypes[i][0] * boxTypes[i][1];
                size += boxTypes[i][0];
            }
        }
        return totalUnits;
    }
};