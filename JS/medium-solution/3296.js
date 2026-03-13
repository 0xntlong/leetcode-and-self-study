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



/**
 * @param {number} mountainHeight
 * @param {number[]} workerTimes
 * @return {number}
 */
var minNumberOfSeconds = function(mountainHeight, workerTimes) {
    let maxT = Math.max(...workerTimes);
    let n = workerTimes.length;
    let v = Math.ceil(mountainHeight / n);
    let start = 0;
    let end = maxT * v * (v + 1) / 2;
    let res = end;

    while (start <= end) {
        let mid = Math.floor(start + (end - start) / 2);
        let totalHeight = 0;

        for (let t of workerTimes) {
            let x = Math.floor((-1 + Math.sqrt(1 + 8 * mid / t)) / 2);
            totalHeight += x;
            if (totalHeight >= mountainHeight) 
                break;
        }

        if (totalHeight >= mountainHeight) {
            res = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return res;
};