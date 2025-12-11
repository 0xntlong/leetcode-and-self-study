/**
3531. Count Covered Buildings
    You are given a positive integer n, representing an n x n city. You are also given a 2D grid buildings, where buildings[i] = [x, y] denotes a unique building located at coordinates [x, y].
    A building is covered if there is at least one building in all four directions: left, right, above, and below.
    Return the number of covered buildings.

    Example :
    Input: n = 3, buildings = [[1,2],[2,2],[3,2],[2,1],[2,3]]
    Output: 1
    Explanation:
    Only building [2,2] is covered as it has at least one building:
    above ([1,2])
    below ([3,2])
    left ([2,1])
    right ([2,3])
    Thus, the count of covered buildings is 1.
 */



function countCoveredBuildings(n: number, buildings: number[][]): number {
    const dict_x: Map<number, number[]> = new Map();
    const dict_y: Map<number, number[]> = new Map();

    for (let [x, y] of buildings) {
        if (!dict_x.has(x)) dict_x.set(x, []);
        dict_x.get(x)?.push(y);

        if (!dict_y.has(y)) dict_y.set(y, []);
        dict_y.get(y)?.push(x);
    }

    dict_x.forEach((value) => value.sort((a, b) => a - b));
    dict_y.forEach((value) => value.sort((a, b) => a - b));

    let res = 0;
    for (let [x, y] of buildings) {
        const ox = dict_x.get(x)!;
        const oy = dict_y.get(y)!;
        if (oy[0] < x && oy[oy.length - 1] > x && ox[0] < y && ox[ox.length - 1] > y) {
            res++;
        }
    }

    return res;
};