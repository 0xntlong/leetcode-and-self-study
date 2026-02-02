/**
3453. Separate Squares I
    You are given a 2D integer array squares. Each squares[i] = [xi, yi, li] represents the coordinates of the bottom-left point and the side length of a square parallel to the x-axis.
    Find the minimum y-coordinate value of a horizontal line such that the total area of the squares above the line equals the total area of the squares below the line.
    Answers within 10-5 of the actual answer will be accepted.
    Note: Squares may overlap. Overlapping areas should be counted multiple times.

    Example :
    Input: squares = [[0,0,1],[2,2,1]]
    Output: 1.00000
    Explanation:
    Any horizontal line between y = 1 and y = 2 will have 1 square unit above it and 1 square unit below it. The lowest option is 1.
 */



function separateSquares1(squares: number[][]): number {
    let total = 0n;
    const diff = new Map<bigint, bigint>();

    for (const sq of squares) {
        const y = BigInt(sq[1]);
        const s = BigInt(sq[2]);
        total += s * s;
        diff.set(y, (diff.get(y) ?? 0n) + s);
        diff.set(y + s, (diff.get(y + s) ?? 0n) - s);
    }

    const curr = Array.from(diff.keys()).sort((a, b) => (a < b ? -1 : a > b ? 1 : 0));

    let area = 0n;
    let target = 0n;

    for (let i = 0; i + 1 < curr.length; i++) {
        const y = curr[i];
        const y2 = curr[i + 1];

        target += diff.get(y)!;
        area += target * (y2 - y);

        if (area * 2n >= total) {
            return Number(y2) - Number(area * 2n - total) / Number(target * 2n);
        }
    }

    return Number(curr[curr.length - 1]);
};