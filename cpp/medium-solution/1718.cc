/*
1718. Construct the Lexicographically Largest Valid Sequence
    Given an integer n, find a sequence that satisfies all of the following:
    The integer 1 occurs once in the sequence.
    Each integer between 2 and n occurs twice in the sequence.
    For every integer i between 2 and n, the distance between the two occurrences of i is exactly i.
    The distance between two numbers on the sequence, a[i] and a[j], is the absolute difference of their indices, |j - i|.
    Return the lexicographically largest sequence. It is guaranteed that under the given constraints, there is always a solution.
    A sequence a is lexicographically larger than a sequence b (of the same length) if in the first position where a and b differ, sequence a has a number greater than the corresponding number in b. For example, [0,1,9,0] is lexicographically larger than [0,1,5,6] because the first position they differ is at the third number, and 9 is greater than 5.

    Example :
    Input: n = 3
    Output: [3,1,2,3,2]
    Explanation: [2,3,2,1,3] is also a valid sequence, but [3,1,2,3,2] is the lexicographically largest valid sequence.
*/

#include <bitset>
#include <vector>
using namespace std;
class Solution {
    public:
        int n, length;
        bitset<21> used = 0;
        vector<int> sequence;
        bool dfs(int pos){
            if (pos == length)
                return used.count() == n;
            if (sequence[pos] != 0)
                return dfs(pos + 1);
            for (int j = n; j >= 1; j--){
                if (used[j])
                    continue;
                int next_pos = (j > 1) ? pos + j : pos;
                if (next_pos >= length || sequence[next_pos] != 0)
                    continue;
                sequence[pos] = sequence[next_pos] = j;
                used[j] = 1;
                if (dfs(pos + 1))
                    return true;
                sequence[pos] = sequence[next_pos] = 0;
                used[j] = 0;
            }
            return false;
        }
        vector<int> constructDistancedSequence(int n) {
            this -> n = n;
            length = 2 * n - 1;
            sequence.assign(length, 0);
            dfs(0);
            return sequence;
        }
    };