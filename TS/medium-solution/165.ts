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



function compareVersion(version1: string, version2: string): number {
    const v1: string[] = version1.split('.');
    const v2: string[] = version2.split('.');
    const n: number = Math.max(v1.length, v2.length);
    for (let i = 0; i < n; i++) {
        const num1: number = i < v1.length ? parseInt(v1[i], 10) : 0;
        const num2: number = i < v2.length ? parseInt(v2[i], 10) : 0;

        if (num1 < num2) 
            return -1;
        if (num1 > num2) 
            return 1;
    }
    return 0;
};