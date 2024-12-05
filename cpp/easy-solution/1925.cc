/*
1925. Count Square Sum Triples
    A square triple (a,b,c) is a triple where a, b, and c are integers and a2 + b2 = c2.
    Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.

    Example :
    Input: n = 5
    Output: 2
    Explanation: The square triples are (3,4,5) and (4,3,5).
*/

#include <cmath>
using namespace std;
class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        for (int i = 3, sq_i; i < n; i++){
            sq_i = i * i;
            for (int j = 3, sq_j , c; j < n; j++){
                sq_j = sq_i + j*j;
                c = sqrt(sq_j);
                if (c > n)
                    break;
                count += c * c == sq_j;
            }
        }
        return count;
    }
};