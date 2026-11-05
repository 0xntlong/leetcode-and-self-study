/*
1385. Find the Distance Value Between Two Arrays
    Given two integer arrays arr1 and arr2, and the integer d, return the distance value between the two arrays.
    The distance value is defined as the number of elements arr1[i] such that there is not any element arr2[j] where |arr1[i]-arr2[j]| <= d.

    Example :
    Input: arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
    Output: 2
    Explanation: 
    For arr1[0]=4 we have: 
    |4-10|=6 > d=2 
    |4-9|=5 > d=2 
    |4-1|=3 > d=2 
    |4-8|=4 > d=2 
    For arr1[1]=5 we have: 
    |5-10|=5 > d=2 
    |5-9|=4 > d=2 
    |5-1|=4 > d=2 
    |5-8|=3 > d=2
    For arr1[2]=8 we have:
    |8-10|=2 <= d=2
    |8-9|=1 <= d=2
    |8-1|=7 > d=2
    |8-8|=0 <= d=2
*/


function findTheDistanceValue(arr1: number[], arr2: number[], d: number): number {
    arr2.sort((a, b) => a - b);
    let ans = 0;

    for (const num of arr1) {
        let left = -1, right = arr2.length;
        let found = false;

        while (right - left > 1) {
            const mid = left + Math.floor((right - left) / 2);
            if (Math.abs(num - arr2[mid]) <= d) {
                found = true;
                break;
            }
            if (arr2[mid] < num) left = mid;
            else right = mid;
        }

        if (!found) ans++;
    }

    return ans;
};