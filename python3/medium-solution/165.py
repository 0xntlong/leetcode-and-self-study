"""
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
"""



class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1 = version1.split('.')
        v2 = version2.split('.')
        n1 = len(v1)
        n2 = len(v2)
        while n1 < n2:
            v1.append('0')
            n1 += 1
        while n1 > n2:
            v2.append('0')
            n2 += 1
        for i1, i2 in zip(v1, v2):
            if (int(i1) < int(i2)):
                return -1
            elif (int(i1)) > (int(i2)):
                return 1
        return 0