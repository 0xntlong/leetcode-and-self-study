/**
3700. Number of ZigZag Arrays II
    You are given three integers n, l, and r.
    A ZigZag array of length n is defined as follows:
    Each element lies in the range [l, r].
    No two adjacent elements are equal.
    No three consecutive elements form a strictly increasing or strictly decreasing sequence.
    Return the total number of valid ZigZag arrays.
    Since the answer may be large, return it modulo 109 + 7.
    A sequence is said to be strictly increasing if each element is strictly greater than its previous one (if exists).
    A sequence is said to be strictly decreasing if each element is strictly smaller than its previous one (if exists).
    Example :
    Input: n = 3, l = 4, r = 5
    Output: 2
    Explanation:
    There are only 2 valid ZigZag arrays of length n = 3 using values in the range [4, 5]:
    [4, 5, 4]
    [5, 4, 5]
 */



function zigZagArrays(n: number, l: number, r: number): number {
    const MOD = 1000000007n;
    const valueCount = r - l + 1;

    const initialDp: bigint[] = Array.from({ length: valueCount }, (_, i) => BigInt(i));

    const transitionMatrix: bigint[][] = Array.from(
        { length: valueCount },
        () => Array(valueCount).fill(0n)
    );

    for (let row = 1; row < valueCount; row++) {
        for (let col = valueCount - row; col < valueCount; col++) {
            transitionMatrix[row][col] = 1n;
        }
    }

    const multiplyMatrices = (matrixA: bigint[][], matrixB: bigint[][]): bigint[][] => {
        const size = matrixA.length;
        const result: bigint[][] = Array.from(
            { length: size },
            () => Array(size).fill(0n)
        );

        for (let row = 0; row < size; row++) {
            for (let mid = 0; mid < size; mid++) {
                if (matrixA[row][mid] === 0n) continue;

                for (let col = 0; col < size; col++) {
                    result[row][col] =
                        (result[row][col] + matrixA[row][mid] * matrixB[mid][col]) % MOD;
                }
            }
        }

        return result;
    };

    const matrixPower = (matrix: bigint[][], power: number): bigint[][] => {
        const size = matrix.length;

        let result: bigint[][] = Array.from({ length: size }, (_, row) =>
            Array.from({ length: size }, (_, col) => row === col ? 1n : 0n)
        );

        while (power > 0) {
            if (power & 1) {
                result = multiplyMatrices(result, matrix);
            }

            matrix = multiplyMatrices(matrix, matrix);
            power >>= 1;
        }

        return result;
    };

    const poweredTransition = matrixPower(transitionMatrix, n - 2);

    let answer = 0n;

    for (let row = 0; row < valueCount; row++) {
        for (let col = 0; col < valueCount; col++) {
            answer = (answer + poweredTransition[row][col] * initialDp[col]) % MOD;
        }
    }

    return Number((answer * 2n) % MOD);
}