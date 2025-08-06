/**
3479. Fruits Into Baskets III
    You are given two arrays of integers, fruits and baskets, each of length n, where fruits[i] represents the quantity of the ith type of fruit, and baskets[j] represents the capacity of the jth basket.
    From left to right, place the fruits according to these rules:
    Each fruit type must be placed in the leftmost available basket with a capacity greater than or equal to the quantity of that fruit type.
    Each basket can hold only one type of fruit.
    If a fruit type cannot be placed in any basket, it remains unplaced.
    Return the number of fruit types that remain unplaced after all possible allocations are made.

    Example :
    Input: fruits = [4,2,5], baskets = [3,5,4]
    Output: 1
    Explanation:
    fruits[0] = 4 is placed in baskets[1] = 5.
    fruits[1] = 2 is placed in baskets[0] = 3.
    fruits[2] = 5 cannot be placed in baskets[2] = 4.
    Since one fruit type remains unplaced, we return 1.
 */

#include <vector>
using namespace std;

class SegmentTree {
public:
    vector<int> seg;
    int n;
    SegmentTree(const vector<int>& data){
        n = data.size();
        seg.resize(4 * n, -1);
        build(data, 1, 0, n - 1);
    }
    void build(const vector<int>& data, int idx, int l, int r){
        if (l == r){
            seg[idx] = data[l];
        } else {
            int m = (l + r) / 2;
            build(data, 2 * idx, l, m);
            build(data, 2 * idx + 1, m + 1, r);
            seg[idx] = max(seg[2 * idx], seg[2 * idx + 1]);
        }
    }
    int search(int idx, int l, int r, int k){
        if (seg[idx] < k){
            return -1;
        }
        if (l == r){
            seg[idx] = -1;
            return l;
        }
        int m = (l + r) / 2;
        int pos;
        if (seg[2 * idx] >= k){
            pos = search(2 * idx, l, m , k);
        } else {
            pos = search(2 * idx + 1, m + 1, r, k);
        }
        seg[idx] = max(seg[2 * idx], seg[2 * idx + 1]);
        return pos;
    }
};
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int unplaced = 0;
        SegmentTree tree(baskets);
        for (int fruit : fruits){
            if (tree.search(1, 0, n - 1, fruit) == -1){
                unplaced++;
            }
        }
        return unplaced;
    }
};