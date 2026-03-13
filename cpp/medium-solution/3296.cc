/**
3296. Minimum Number of Seconds to Make Mountain Height Zero
    You are given an integer mountainHeight denoting the height of a mountain.
    You are also given an integer array workerTimes representing the work time of workers in seconds.
    The workers work simultaneously to reduce the height of the mountain. For worker i:
    To decrease the mountain's height by x, it takes workerTimes[i] + workerTimes[i] * 2 + ... + workerTimes[i] * x seconds. For example:
    To reduce the height of the mountain by 1, it takes workerTimes[i] seconds.
    To reduce the height of the mountain by 2, it takes workerTimes[i] + workerTimes[i] * 2 seconds, and so on.
    Return an integer representing the minimum number of seconds required for the workers to make the height of the mountain 0.

    Example :
    Input: mountainHeight = 4, workerTimes = [2,1,1]
    Output: 3
    Explanation:
    One way the height of the mountain can be reduced to 0 is:
    Worker 0 reduces the height by 1, taking workerTimes[0] = 2 seconds.
    Worker 1 reduces the height by 2, taking workerTimes[1] + workerTimes[1] * 2 = 3 seconds.
    Worker 2 reduces the height by 1, taking workerTimes[2] = 1 second.
    Since they work simultaneously, the minimum time needed is max(2, 3, 1) = 3 seconds.
 */


#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int n = workerTimes.size();
        long long totalTime = 0;
        for (int t : workerTimes) {
            totalTime += t;
        }

        long long v = (long long)ceil((double)mountainHeight / n);

        long long start = 1;
        long long end = v * (v + 1) * *max_element(workerTimes.begin(), workerTimes.end()) / 2;

        while (start < end) {
            long long mid = (start + end) / 2;
            long long totalWork = 0;
            for (int t : workerTimes) {
                totalWork += (long long)floor(sqrt(2 * mid / (double)t + 0.25) - 0.5);
            }

            if (totalWork >= mountainHeight) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }

        return start;
    }
};