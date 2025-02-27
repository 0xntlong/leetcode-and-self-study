/*
873. Length of Longest Fibonacci Subsequence
    A sequence x1, x2, ..., xn is Fibonacci-like if:
    n >= 3
    xi + xi+1 == xi+2 for all i + 2 <= n
    Given a strictly increasing array arr of positive integers forming a sequence, return the length of the longest Fibonacci-like subsequence of arr. If one does not exist, return 0.
    A subsequence is derived from another sequence arr by deleting any number of elements (including none) from arr, without changing the order of the remaining elements. For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].

    Example :
    Input: arr = [1,2,3,4,5,6,7,8]
    Output: 5
    Explanation: The longest subsequence that is fibonacci-like: [1,2,3,5,8].
*/

#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
    public:
        int lenLongestFibSubseq(vector<int>& arr) {
            unordered_set<int> num_set(arr.begin(), arr.end());
            int maxLength = 0;
            int n = arr.size();
            for (int i = 0; i < n - 1; i++){
                for (int j = i + 1; j < n; j++){
                    int a = arr[i], b = arr[j];
                    int length = 2;
                    while (num_set.count(a + b)){
                        int temp = a + b;
                        a = b;
                        b = temp;
                        length++;
                    }
                    maxLength = max(maxLength, length);
                }
            }
            return maxLength > 2 ? maxLength : 0;
        }
    };