/**
1386. Cinema Seat Allocation
    A cinema has n rows of seats, numbered from 1 to n. Each row has 10 seats, numbered from 1 to 10.
    You are given a 2D integer array reservedSeats, where reservedSeats[i] = [rowi, seati] means that seat seati in row rowi is already reserved.
    A four-person group must be assigned to four seats in the same row. The group can be seated in one of the following seat blocks:
    seats 2, 3, 4, 5
    seats 4, 5, 6, 7
    seats 6, 7, 8, 9
    A block can be used only if none of its seats are reserved. Each seat can be assigned to at most one group.
    Return an integer denoting the maximum number of four-person groups that can be assigned.

    Example :
    Input: n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
    Output: 4
    Explanation: The figure above shows an optimal allocation of four groups. Seats marked in blue are already reserved, and each set of four contiguous seats marked in orange is assigned to one group.
 */



function maxNumberOfFamilies(n: number, reservedSeats: number[][]): number {
    const rows: Map<number, number> = new Map();

    for (const [row, seat] of reservedSeats) {
        if (seat === 1 || seat === 10) {
            continue;
        }

        const mask = rows.get(row) ?? 0;
        rows.set(row, mask | (1 << seat));
    }

    let total: number = (n - rows.size) * 2;

    let leftMask = 0;
    let middleMask = 0;
    let rightMask = 0;

    for (let seat = 2; seat <= 5; seat++) {
        leftMask |= 1 << seat;
    }

    for (let seat = 4; seat <= 7; seat++) {
        middleMask |= 1 << seat;
    }

    for (let seat = 6; seat <= 9; seat++) {
        rightMask |= 1 << seat;
    }

    for (const mask of rows.values()) {
        const leftFree = (mask & leftMask) === 0;
        const middleFree = (mask & middleMask) === 0;
        const rightFree = (mask & rightMask) === 0;

        if (leftFree && rightFree) {
            total += 2;
        } else if (leftFree || middleFree || rightFree) {
            total += 1;
        }
    }

    return total;
};