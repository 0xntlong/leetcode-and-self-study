/**
3414. Maximum Score of Non-overlapping Intervals
    You are given a 2D integer array intervals, where intervals[i] = [li, ri, weighti]. Interval i starts at position li and ends at ri, and has a weight of weighti. You can choose up to 4 non-overlapping intervals. The score of the chosen intervals is defined as the total sum of their weights.
    Return the lexicographically smallest array of at most 4 indices from intervals with maximum score, representing your choice of non-overlapping intervals.
    Two intervals are said to be non-overlapping if they do not share any points. In particular, intervals sharing a left or right boundary are considered overlapping.
    Example:
    Input: intervals = [[1,3,2],[4,5,2],[1,5,5],[6,9,3],[6,7,1],[8,9,1]]
    Output: [2,3]
    Explanation:
    You can choose the intervals with indices 2, and 3 with respective weights of 5, and 3.
 */



function maximumWeight(intervals: number[][]): number[] {
    const arr: number[][] = [];

    for (let i = 0; i < intervals.length; i++) {
        const [left, right, weight] = intervals[i];
        arr.push([right, left, weight, i]);
    }

    arr.sort((a, b) => {
        if (a[0] !== b[0]) return a[0] - b[0];
        if (a[1] !== b[1]) return a[1] - b[1];
        return a[3] - b[3];
    });

    const n = arr.length;
    const rightEnds: number[] = arr.map(item => item[0]);

    type State = [number, number[]];

    let previous: State[] = Array.from(
        { length: n + 1 },
        (): State => [0, []]
    );

    const better = (a: State, b: State): State => {
        if (a[0] !== b[0]) {
            return a[0] > b[0] ? a : b;
        }

        const x = a[1];
        const y = b[1];

        const size = Math.min(x.length, y.length);

        for (let i = 0; i < size; i++) {
            if (x[i] !== y[i]) {
                return x[i] < y[i] ? a : b;
            }
        }

        return x.length <= y.length ? a : b;
    };

    const lowerBound = (end: number, target: number): number => {
        let left = 0;
        let right = end;

        while (left < right) {
            const mid = Math.floor((left + right) / 2);

            if (rightEnds[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    };

    for (let selectedCount = 1; selectedCount <= 4; selectedCount++) {
        const current: State[] = Array.from(
            { length: n + 1 },
            (): State => [0, []]
        );

        for (let i = 1; i <= n; i++) {
            const [right, left, weight, originalIndex] = arr[i - 1];

            const skip: State = current[i - 1];

            const previousCount = lowerBound(i - 1, left);

            const [oldScore, oldIndices] = previous[previousCount];

            const newIndices: number[] = [...oldIndices, originalIndex];
            newIndices.sort((a, b) => a - b);

            const take: State = [
                oldScore + weight,
                newIndices
            ];

            current[i] = better(skip, take);
        }

        previous = current;
    }

    return previous[n][1];
}