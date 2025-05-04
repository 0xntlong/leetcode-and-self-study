/**
1128. Number of Equivalent Domino Pairs
    Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a == c and b == d), or (a == d and b == c) - that is, one domino can be rotated to be equal to another domino.
    Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].

    Example :
    Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
    Output: 1
 */


    function numEquivDominoPairs(dominoes: number[][]): number {
        const counter = new Map<number, number>();
        let res = 0;
        for (let domino of dominoes){
            const equi = Math.min(domino[0], domino[1]) * 10 + Math.max(domino[0], domino[1]);
            counter.set(equi, (counter.get(equi) || 0) + 1);
        }
        for (let count of counter.values()){
            res += (count * (count - 1)) / 2;
        }
        return res;
    };