/**
2081. Sum of k-Mirror Numbers
    A k-mirror number is a positive integer without leading zeros that reads the same both forward and backward in base-10 as well as in base-k.
    For example, 9 is a 2-mirror number. The representation of 9 in base-10 and base-2 are 9 and 1001 respectively, which read the same both forward and backward.
    On the contrary, 4 is not a 2-mirror number. The representation of 4 in base-2 is 100, which does not read the same both forward and backward.
    Given the base k and the number n, return the sum of the n smallest k-mirror numbers.

    Example :
    Input: k = 2, n = 5
    Output: 25
    Explanation:
    The 5 smallest 2-mirror numbers and their representations in base-2 are listed as follows:
    base-10    base-2
        1          1
        3          11
        5          101
        7          111
        9          1001
    Their sum = 1 + 3 + 5 + 7 + 9 = 25.
 */

#include <vector>
#include <cmath>
#include <string>
using namespace std;
class Solution {
public:
    long long reverse(long long x){
        long long res = 0;
        while (x > 0){
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
    bool Palindrome(long long x, int k){
        vector<int> digit;
        while (x > 0){
            digit.push_back(x % k);
            x /= k;
        }
        int i = 0, j = digit.size() - 1;
        while (i < j){
            if (digit[i] != digit[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    long long isPalindrome(int mid, bool odd){
        int len = to_string(mid).length();
        if (odd){
            return mid * pow(10, len - 1) + reverse(mid / 10);
        } else {
            return mid * pow(10, len) + reverse(mid);
        }
    }
    long long kMirror(int k, int n) {
        long long total = 0;
        int length = 1;
        while (true){
            int mid = (length + 1) / 2;
            int start = pow(10, mid - 1);
            int end = pow(10, mid);
            for (int i = start; i < end; i++){
                long long pal = isPalindrome(i, length % 2 == 1);
                if (Palindrome(pal, k)){
                    total += pal;
                    n--;
                    if (n == 0){
                        return total;
                    }
                }
            }
            length++;
        }
    }
};