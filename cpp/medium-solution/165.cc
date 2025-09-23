/**
165. Compare Version Numbers
    Given two version strings, version1 and version2, compare them. A version string consists of revisions separated by dots '.'. The value of the revision is its integer conversion ignoring leading zeros.
    To compare version strings, compare their revision values in left-to-right order. If one of the version strings has fewer revisions, treat the missing revision values as 0.
    Return the following:
    If version1 < version2, return -1.
    If version1 > version2, return 1.
    Otherwise, return 0.
    Example:
    Input: version1 = "1.2", version2 = "1.10"
    Output: -1
    Explanation:
    version1's second revision is "2" and version2's second revision is "10": 2 < 10, so version1 < version2.
 */


#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> v1, v2;
        string token;
        stringstream ss1(version1), ss2(version2);
        while (getline(ss1, token, '.'))
            v1.push_back(token);
        while (getline(ss2, token, '.'))
            v2.push_back(token);
        int n1 = v1.size(), n2 = v2.size();
        int n = max(n1, n2);
        for (int i = 0; i < n; i++){
            int num1 = i < n1 ? stoi(v1[i]) : 0;
            int num2 = i < n2 ? stoi(v2[i]) : 0;
            if (num1 < num2)    
                return -1;
            if (num1 > num2)
                return 1;
        }
        return 0;
    }
};