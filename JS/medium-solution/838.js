/**
838. Push Dominoes
    There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.
    After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.
    When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.
    For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.
    You are given a string dominoes representing the initial state where:
    dominoes[i] = 'L', if the ith domino has been pushed to the left,
    dominoes[i] = 'R', if the ith domino has been pushed to the right, and
    dominoes[i] = '.', if the ith domino has not been pushed.
    Return a string representing the final state.

    Example :
    Input: dominoes = "RR.L"
    Output: "RR.L"
    Explanation: The first domino expends no additional force on the second domino.
 */


/**
 * @param {string} dominoes
 * @return {string}
 */
var pushDominoes = function(dominoes) {
    const n = dominoes.length;
    const vector = new Array(n);
    let i = 0;
    for (let j = n - 1; j >= 0; j--){
        let c = dominoes[j];
        if (c === 'L'){
            i = n;
        } else if (c === 'R'){
            i = 0;
        } else if (c === '.'){
            if (i > 0){
                i--;
            }
        }
        vector[j] = i;
    }
    i = 0;
    let res = [...dominoes];
    for (let j = 0; j < n; j++){
        let c = res[j];
        if (c === 'L'){
            i = 0;
        } else if (c === 'R'){
            i = n;
        } else if (c === '.'){
            if (i > 0){
                i--;
            } if ( i < vector[j]){
                res[j] = 'L';
            } else if (i > vector[j]){
                res[j] = 'R';
            }
        }
    }
    return res.join('');
};