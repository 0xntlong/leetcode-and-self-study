/**
3394. Check if Grid can be Cut into Sections
    You are given an integer n representing the dimensions of an n x n grid, with the origin at the bottom-left corner of the grid. You are also given a 2D array of coordinates rectangles, where rectangles[i] is in the form [startx, starty, endx, endy], representing a rectangle on the grid. Each rectangle is defined as follows:
    (startx, starty): The bottom-left corner of the rectangle.
    (endx, endy): The top-right corner of the rectangle.
    Note that the rectangles do not overlap. Your task is to determine if it is possible to make either two horizontal or two vertical cuts on the grid such that:
    Each of the three resulting sections formed by the cuts contains at least one rectangle.
    Every rectangle belongs to exactly one section.
    Return true if such cuts can be made; otherwise, return false.
    Example :
    Input: n = 5, rectangles = [[1,0,5,2],[0,2,2,4],[3,2,5,3],[0,4,4,5]]
    Output: true
*/

function check(a: [number, number][], n: number): boolean {
    let temp: [number, number][] = [a[0]];
    for (let i = 1; i < n; i++) {
        if (a[i][0] >= temp[temp.length - 1][1])
            temp.push(a[i]);
        else
            temp[temp.length - 1] = [temp[temp.length - 1][0], Math.max(temp[temp.length - 1][1], a[i][1])];
    }
    return temp.length >= 3;
}

function checkValidCuts(n: number, rectangles: number[][]): boolean {
    let m = rectangles.length;
    let x: [number, number][] = [];
    let y: [number, number][] = [];
    for (let r of rectangles) {
        x.push([r[0], r[2]]);
        y.push([r[1], r[3]]);
    }
    x.sort((a, b) => a[0] - b[0]);
    y.sort((a, b) => a[0] - b[0]);
    return check(x, m) || check(y, m);
}