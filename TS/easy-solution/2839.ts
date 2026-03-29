/**
2839. Check if Strings Can be Made Equal With Operations I
    You are given two strings s1 and s2, both of length 4, consisting of lowercase English letters.
    You can apply the following operation on any of the two strings any number of times:
    Choose any two indices i and j such that j - i = 2, then swap the two characters at those indices in the string.
    Return true if you can make the strings s1 and s2 equal, and false otherwise.

    Example :
    Input: s1 = "abcd", s2 = "cdab"
    Output: true
    Explanation: We can do the following operations on s1:
    - Choose the indices i = 0, j = 2. The resulting string is s1 = "cbad".
    - Choose the indices i = 1, j = 3. The resulting string is s1 = "cdab" = s2.
 */


function canBeEqual(s1: string, s2: string): boolean {
    let even_s1 = [s1[0], s1[2]].sort();
    let even_s2 = [s2[0], s2[2]].sort();
        
    let odd_s1 = [s1[1], s1[3]].sort();
    let odd_s2 = [s2[1], s2[3]].sort();
        
    return even_s1.toString() === even_s2.toString() && odd_s1.toString() === odd_s2.toString();
};