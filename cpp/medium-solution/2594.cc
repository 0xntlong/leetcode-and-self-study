/*
2594. Minimum Time to Repair Cars
    You are given an integer array ranks representing the ranks of some mechanics. ranksi is the rank of the ith mechanic. A mechanic with a rank r can repair n cars in r * n2 minutes.
    You are also given an integer cars representing the total number of cars waiting in the garage to be repaired.
    Return the minimum time taken to repair all the cars.
    Note: All the mechanics can repair the cars simultaneously.
    Example :
    Input: ranks = [4,2,3,1], cars = 10
    Output: 16
    Explanation: 
    - The first mechanic will repair two cars. The time required is 4 * 2 * 2 = 16 minutes.
    - The second mechanic will repair two cars. The time required is 2 * 2 * 2 = 8 minutes.
    - The third mechanic will repair two cars. The time required is 3 * 2 * 2 = 12 minutes.
    - The fourth mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
    It can be proved that the cars cannot be repaired in less than 16 minutes.
*/

#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution {
    public:
        long long canFixInTime(vector<int>& ranks, long long T, int cars){
            long long total_cars = 0;
            for (int r : ranks){
                total_cars += sqrt(T / r);
                if (total_cars >= cars)
                    return true;
            }
            return total_cars >= cars;
        }
        long long repairCars(vector<int>& ranks, int cars) {
            long long left = 1, right = *max_element(ranks.begin(), ranks.end())  * (long long) cars * cars;
            while (left < right){
                long long mid = (left + right) / 2;
                if (canFixInTime(ranks, mid, cars)){
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        }
    };