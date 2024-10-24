/*
1394. Find Lucky Integer in an Array
    Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.
    Return the largest lucky integer in the array. If there is no lucky integer return -1.
    
    Example :
    Input: arr = [2,2,3,4]
    Output: 2
    Explanation: The only lucky number in the array is 2 because frequency[2] == 2.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int>hash_map;
        int n = arr.size();
        int lucky = -1;
        for (int i : arr){
            hash_map[i]++;
        }
        for (auto i : hash_map){
            if ( i.first == i.second){
                lucky = max(lucky,i.first);
            }
        }
        return lucky;
    }
};