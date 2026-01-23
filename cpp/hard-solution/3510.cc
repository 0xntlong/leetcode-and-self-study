/**
3510. Minimum Pair Removal to Sort Array II
    Given an array nums, you can perform the following operation any number of times:
    Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
    Replace the pair with their sum.
    Return the minimum number of operations needed to make the array non-decreasing.
    An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).

    Example :
    Input: nums = [5,2,3,1]
    Output: 2
    Explanation:
    The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
    The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
    The array nums became non-decreasing in two operations.
 */

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = (int)nums.size();
        if (n <= 1) 
            return 0;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) a[i] = nums[i];
        vector<int> left(n, -1);
        vector<int> right(n, -1);
        for (int i = 0; i < n; i++) {
            left[i] = i - 1;
            right[i] = (i + 1 < n) ? i + 1 : -1;
        }
        using P = pair<long long, int>;
        priority_queue<P, vector<P>, greater<P>> heap;
        for (int i = 0; i < n - 1; i++) {
            heap.push({a[i] + a[i + 1], i});
        }

        int rest = 0;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) rest++;
        }

        auto bad = [&](int x, int y) -> bool {
            return a[x] > a[y];
        };

        int ans = 0;

        while (rest > 0) {
            auto [v, i] = heap.top(); heap.pop();

            int r = right[i];
            if (r == -1) 
                continue;                 
            if (left[r] != i) 
                continue;            
            if (a[i] + a[r] != v) 
                continue;        

            int li = left[i];
            int rr = right[r];

            if (li != -1 && right[li] == i && bad(li, i)) 
                rest--;
            if (bad(i, r)) 
                rest--;
            if (rr != -1 && left[rr] == r && bad(r, rr)) 
                rest--;

            a[i] = v;

            right[i] = rr;
            if (rr != -1) left[rr] = i;
            left[r] = right[r] = -1;


            if (li != -1 && right[li] == i && bad(li, i)) 
                rest++;
            if (rr != -1 && left[rr] == i && bad(i, rr)) 
                rest++;

            if (li != -1 && right[li] == i) {
                heap.push({a[li] + a[i], li});
            }
            if (rr != -1 && left[rr] == i) {
                heap.push({a[i] + a[rr], i});
            }

            ans++;
        }

        return ans;
    }
};