"""
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
"""

from typing import List
class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key = lambda x : x[1], reverse = True)
        totalUnits = 0
        size = 0
        for box in boxTypes:
            if size + box[0] > truckSize:
                totalUnits += box[1] * (truckSize - size)
                break
            else:
                totalUnits += box[0] * box[1]
                size += box[0]
        return totalUnits