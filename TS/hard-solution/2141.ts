/**
2141. Maximum Running Time of N Computers
    You have n computers. You are given the integer n and a 0-indexed integer array batteries where the ith battery can run a computer for batteries[i] minutes. You are interested in running all n computers simultaneously using the given batteries.
    Initially, you can insert at most one battery into each computer. After that and at any integer time moment, you can remove a battery from a computer and insert another battery any number of times. The inserted battery can be a totally new battery or a battery from another computer. You may assume that the removing and inserting processes take no time.
    Note that the batteries cannot be recharged.
    Return the maximum number of minutes you can run all the n computers simultaneously.

    Example :
    Input: n = 2, batteries = [3,3,3]
    Output: 4
    Explanation: 
    Initially, insert battery 0 into the first computer and battery 1 into the second computer.
    After two minutes, remove battery 1 from the second computer and insert battery 2 instead. Note that battery 1 can still run for one minute.
    At the end of the third minute, battery 0 is drained, and you need to remove it from the first computer and insert battery 1 instead.
    By the end of the fourth minute, battery 1 is also drained, and the first computer is no longer running.
    We can run the two computers simultaneously for at most 4 minutes, so we return 4.
 */



function maxRunTime(n: number, batteries: number[]): number {
    let total_energy = 0;
    for (const b of batteries) {
        total_energy += b;
    }
    let min_batteries = 0;
    let max_batteries = Math.floor(total_energy / n);
    let res = 0;
    while (min_batteries <= max_batteries) {
        const mid = Math.floor((min_batteries + max_batteries + 1) / 2);
        let reverse = 0;

        for (const minute of batteries) {
            reverse += Math.min(minute, mid);
            if (reverse >= mid * n) 
                break;
        }

        if (reverse >= mid * n) {
            res = mid;
            min_batteries = mid + 1;
        } else {
            max_batteries = mid - 1;
        }
    }

    return res;
};