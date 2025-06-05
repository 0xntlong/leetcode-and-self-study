/*
1061. Lexicographically Smallest Equivalent String
    You are given two strings of the same length s1 and s2 and a string baseStr.
    We say s1[i] and s2[i] are equivalent characters.
    For example, if s1 = "abc" and s2 = "cde", then we have 'a' == 'c', 'b' == 'd', and 'c' == 'e'.
    Equivalent characters follow the usual rules of any equivalence relation:
    Reflexivity: 'a' == 'a'.
    Symmetry: 'a' == 'b' implies 'b' == 'a'.
    Transitivity: 'a' == 'b' and 'b' == 'c' implies 'a' == 'c'.
    For example, given the equivalency information from s1 = "abc" and s2 = "cde", "acd" and "aab" are equivalent strings of baseStr = "eed", and "aab" is the lexicographically smallest equivalent string of baseStr.
    Return the lexicographically smallest equivalent string of baseStr by using the equivalency information from s1 and s2.

    Example :
    Input: s1 = "parker", s2 = "morris", baseStr = "parser"
    Output: "makkek"
    Explanation: Based on the equivalency information in s1 and s2, we can group their characters as [m,p], [a,o], [k,r,s], [e,i].
    The characters in each group are equivalent and sorted in lexicographical order.
    So the answer is "makkek".
 */

#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    char find(char x, vector<char>& root){
        if (root[x - 'a'] != x){
            root[x - 'a'] = find(root[x - 'a'], root);
        }
        return root[x - 'a'];
    }
    void unionSet(char x, char y, vector<char>& root){
        char r1 = find(x, root);
        char r2 = find(y, root);
        if (r1 != r2){
            if (r1 < r2){
                root[r2 - 'a'] = r1;
            } else {
                root[r1 - 'a'] = r2;
            }
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<char> root(26);
        for (char i = 0; i < 26; i++){
            root[i] = 'a' + i;
        }
        for (int i = 0; i < s1.size(); i++){
            unionSet(s1[i], s2[i], root);
        }
        string res = "";
        for (char c : baseStr){
            res += find(c, root);
        }
        return res;
    }
};