/*
1356. Sort Integers by The Number of 1 Bits
    You are given an integer array arr. 
    Sort the integers in the array in ascending order by the number of 1's in their binary representation 
    and in case of two or more integers have the same number of 1's you have to sort them in ascending order.
    Return the array after sorting it.
    
    Example :
    Input: arr = [0,1,2,3,4,5,6,7,8]
    Output: [0,1,2,4,8,3,5,6,7]
    Explantion: [0] is the only integer with 0 bits.
    [1,2,4,8] all have 1 bit.
    [3,5,6] have 2 bits.
    [7] has 3 bits.
    The sorted array by bits is [0,1,2,4,8,3,5,6,7]
*/
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto customComparator = [this](int a, int b){
            int oneA = countOnes(a);
            int oneB = countOnes(b);
            if (oneA != oneB){
                return oneA > oneB;
            }
            return a > b;
        };
        priority_queue<int, vector<int>, decltype(customComparator) > priorityQueue(customComparator);
        for (int n : arr){
            priorityQueue.push(n);
        }
        vector<int> res;
        while(!priorityQueue.empty()){
            res.push_back(priorityQueue.top());
            priorityQueue.pop();
        }
        return res;
    }
    int countOnes(int num){
        int count = 0;
        while (num){
            num &= (num - 1);
            count++;
        }
        return count;
    }
};