/*
1861. Rotating the Box
    You are given an m x n matrix of characters box representing a side-view of a box. Each cell of the box is one of the following:
    A stone '#'
    A stationary obstacle '*'
    Empty '.'
    The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.
    It is guaranteed that each stone in box rests on an obstacle, another stone, or the bottom of the box.
    Return an n x m matrix representing the box after the rotation described above.

    Example :
    Input: box = [["#",".","#"]]
    Output: [["."],
            ["#"],
            ["#"]]
*/

function rotateTheBox(boxGrid: string[][]): string[][] {
    const row = boxGrid.length;
    const col = boxGrid[0].length;
    const rotate: string[][] = Array.from({ length: col }, () =>
        Array(row).fill('.')
    );
    for (let k = 0; k < row; k++) {
        let bottom = col - 1;
        for (let j = col - 1; j >= 0; j--) {
            if (boxGrid[k][j] === '#') {
                rotate[bottom][row - 1 - k] = '#';
                bottom--;
            } 
            else if (boxGrid[k][j] === '*') {
                rotate[j][row - 1 - k] = '*';
                bottom = j - 1;
            }
        }
    }
    return rotate;
};