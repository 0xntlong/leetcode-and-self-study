/**
2528. Maximize the Minimum Powered City
    You are given a 0-indexed integer array stations of length n, where stations[i] represents the number of power stations in the ith city.
    Each power station can provide power to every city in a fixed range. In other words, if the range is denoted by r, then a power station at city i can provide power to all cities j such that |i - j| <= r and 0 <= i, j <= n - 1.
    Note that |x| denotes absolute value. For example, |7 - 5| = 2 and |3 - 10| = 7.
    The power of a city is the total number of power stations it is being provided power from.
    The government has sanctioned building k more power stations, each of which can be built in any city, and have the same range as the pre-existing ones.
    Given the two integers r and k, return the maximum possible minimum power of a city, if the additional power stations are built optimally.
    Note that you can build the k power stations in multiple cities.

    Example:
    Input: stations = [1,2,4,5,0], r = 1, k = 2
    Output: 5
    Explanation: 
    One of the optimal ways is to install both the power stations at city 1. 
    So stations will become [1,4,4,5,0].
    - City 0 is provided by 1 + 4 = 5 power stations.
    - City 1 is provided by 1 + 4 + 4 = 9 power stations.
    - City 2 is provided by 4 + 4 + 5 = 13 power stations.
    - City 3 is provided by 5 + 4 = 9 power stations.
    - City 4 is provided by 5 + 0 = 5 power stations.
    So the minimum power of a city is 5.
    Since it is not possible to obtain a larger power, we return 5.
 */




class Solution {
public:
    static bool check(long long min_power, vector<int> stations, int r, long long k, int n){
        long long power = reduce(stations.begin(), stations.begin() + r + 1, 0LL);
        for (int i = 0; i < n; i++){
            if (power < min_power){
                long long need = min_power - power;
                if (need > k)
                    return 0;
                k -= need;
                int pos = min(n - 1, i + r);
                stations[pos] += need;
                power += need;
            }
            if (i - r >= 0){
                power -= stations[i - r];
            }
            if (i + r + 1< n){
                power += stations[i + r + 1];
            }
        }
        return 1;
    }
    static long long maxPower(vector<int>& stations, int r, int k) {
        const int n = stations.size();
        long long left = 0, right = reduce(stations.begin(), stations.end(), 0LL) + k;
        long long ans = 0;
        while (left <= right){
            long long mid = left + (right - left) / 2; 
            if (check(mid, stations, r, k, n)){
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};