/**
1386. Cinema Seat Allocation
    A cinema has n rows of seats, numbered from 1 to n. Each row has 10 seats, numbered from 1 to 10.
    You are given a 2D integer array reservedSeats, where reservedSeats[i] = [rowi, seati] means that seat seati in row rowi is already reserved.
    A four-person group must be assigned to four seats in the same row. The group can be seated in one of the following seat blocks:
    seats 2, 3, 4, 5
    seats 4, 5, 6, 7
    seats 6, 7, 8, 9
    A block can be used only if none of its seats are reserved. Each seat can be assigned to at most one group.
    Return an integer denoting the maximum number of four-person groups that can be assigned.

    Example :
    Input: n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
    Output: 4
    Explanation: The figure above shows an optimal allocation of four groups. Seats marked in blue are already reserved, and each set of four contiguous seats marked in orange is assigned to one group.
 */



#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> seats;

        for (auto& r : reservedSeats) {
            int row = r[0];
            int seat = r[1];

            if (seat >= 2 && seat <= 5) {
                seats[row].insert(0);
            }

            if (seat >= 4 && seat <= 7) {
                seats[row].insert(1);
            }

            if (seat >= 6 && seat <= 9) {
                seats[row].insert(2);
            }
        }

        int total = 2 * n;

        for (auto& [row, groups] : seats) {
            if (groups.size() == 3) {
                total -= 2;
            } else {
                total -= 1;
            }
        }

        return total;
    }
};