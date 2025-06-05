"""
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
"""


class Solution:
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]
        
        def union(x, y):
            rootX = find(x)
            rootY = find(y)
            if rootX != rootY:
                if rootX < rootY:
                    parent[rootY] = rootX
                else :
                    parent[rootX] = rootY
        
        parent = {chr(i) : chr(i) for i in range(ord('a'), ord('z') + 1)}

        for i1, i2 in zip(s1, s2):
            union(i1, i2)
        res = []
        for c in baseStr:
            res.append(find(c))
        return "".join(res)