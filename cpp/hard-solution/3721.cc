/**
3721. Longest Balanced Subarray II
    You are given an integer array nums.
    A subarray is called balanced if the number of distinct even numbers in the subarray is equal to the number of distinct odd numbers.
    Return the length of the longest balanced subarray.

    Example :
    Input: nums = [2,5,4,3]
    Output: 4
    Explanation:
    The longest balanced subarray is [2, 5, 4, 3].
    It has 2 distinct even numbers [2, 4] and 2 distinct odd numbers [5, 3]. Thus, the answer is 4.
 */


 class Solution {
public:
    struct Node {
        int mn = 0, mx = 0, lz = 0;
    };

    int n;
    std::vector<Node> seg;

    void push(int node) {
        int val = seg[node].lz;
        if (val == 0) return;

        int lc = node << 1, rc = lc | 1;

        seg[lc].mn += val; seg[lc].mx += val; seg[lc].lz += val;
        seg[rc].mn += val; seg[rc].mx += val; seg[rc].lz += val;

        seg[node].lz = 0;
    }

    void pull(int node) {
        int lc = node << 1, rc = lc | 1;
        seg[node].mn = std::min(seg[lc].mn, seg[rc].mn);
        seg[node].mx = std::max(seg[lc].mx, seg[rc].mx);
    }

    void update(int node, int segLeft, int segRight,
                int queryLeft, int queryRight, int addValue) {
        if (queryLeft > queryRight) return;

        if (queryLeft == segLeft && queryRight == segRight) {
            seg[node].mn += addValue;
            seg[node].mx += addValue;
            seg[node].lz += addValue;
            return;
        }

        push(node);
        int mid = (segLeft + segRight) >> 1;

        update(node << 1, segLeft, mid, queryLeft, std::min(queryRight, mid), addValue);
        update(node << 1 | 1, mid + 1, segRight, std::max(queryLeft, mid + 1), queryRight, addValue);
        pull(node);
    }
    int findFirst(int node, int segLeft, int segRight, int limit) {
        if (segLeft > limit) 
            return -1;
        if (seg[node].mn > 0 || seg[node].mx < 0) 
            return -1;
        if (segLeft == segRight) 
            return segLeft;

        push(node);
        int mid = (segLeft + segRight) >> 1;

        int leftRes = findFirst(node << 1, segLeft, mid, limit);
        if (leftRes != -1) 
            return leftRes;

        if (mid < limit) 
            return findFirst(node << 1 | 1, mid + 1, segRight, limit);
        return -1;
    }

    int longestBalanced(std::vector<int>& nums) {
        n = (int)nums.size();
        seg.assign(4 * n + 5, Node());

        std::vector<int> lastPos(100005, -1);

        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            int val = nums[i];
            int prev = lastPos[val];
            int diff = (val & 1) ? -1 : 1;

            update(1, 0, n - 1, prev + 1, i, diff);

            lastPos[val] = i;

            int start = findFirst(1, 0, n - 1, i);
            if (start != -1) {
                maxLen = std::max(maxLen, i - start + 1);
            }
        }
        return maxLen;
    }
};