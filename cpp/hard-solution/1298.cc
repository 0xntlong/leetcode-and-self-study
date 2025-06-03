/*
1298. Maximum Candies You Can Get from Boxes
    You have n boxes labeled from 0 to n - 1. You are given four arrays: status, candies, keys, and containedBoxes where:
    status[i] is 1 if the ith box is open and 0 if the ith box is closed,
    candies[i] is the number of candies in the ith box,
    keys[i] is a list of the labels of the boxes you can open after opening the ith box.
    containedBoxes[i] is a list of the boxes you found inside the ith box.
    You are given an integer array initialBoxes that contains the labels of the boxes you initially have. You can take all the candies in any open box and you can use the keys in it to open new boxes and you also can use the boxes you find in it.
    Return the maximum number of candies you can get following the rules above.

    Example :
    Input: status = [1,0,1,0], candies = [7,5,4,100], keys = [[],[],[1],[]], containedBoxes = [[1,2],[3],[],[]], initialBoxes = [0]
    Output: 16
    Explanation: You will be initially given box 0. You will find 7 candies in it and boxes 1 and 2.
    Box 1 is closed and you do not have a key for it so you will open box 2. You will find 4 candies and a key to box 1 in box 2.
    In box 1, you will find 5 candies and box 3 but you will not find a key to box 3 so box 3 will remain closed.
    Total number of candies collected = 7 + 4 + 5 = 16 candy.
 */


#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int cnt = 0;
        queue<int> q;
        for (auto i : initialBoxes){
            q.push(i);
        }
        while(!q.empty()){
            int sz = q.size();
            vector<int> curr;
            vector<int> inserted;
            while (sz--){
                int box = q.front();
                q.pop();
                curr.push_back(box);
                if (status[box]){
                    cnt += candies[box];
                    for (auto k : keys[box]){
                        status[k] = 1;
                    }
                    for (auto other : containedBoxes[box]){
                        q.push(other);
                    }
                } else {
                    q.push(box);
                    inserted.push_back(box);
                }
            }
            if (curr == inserted){
                break;
            }
        }
        return cnt;
    }
};