/**
3403. Find the Lexicographically Largest String From the Box I
    You are given a string word, and an integer numFriends.
    Alice is organizing a game for her numFriends friends. There are multiple rounds in the game, where in each round:
    word is split into numFriends non-empty strings, such that no previous round has had the exact same split.
    All the split words are put into a box.
    Find the lexicographically largest string from the box after all the rounds are finished.

    Example :
    Input: word = "dbca", numFriends = 2
    Output: "dbc"
    Explanation: 
    All possible splits are:
    "d" and "bca".
    "db" and "ca".
    "dbc" and "a".
 */



function answerString(word: string, numFriends: number): string {
    if (numFriends === 1){
        return word;
    }
    const n = word.length;
    const m = n - numFriends + 1;
    let i = 0, j = 1;
    while (j < n){
        let k = 0;
        while (j + k < n && word.charAt(i + k) === word.charAt(j + k)){
            k++;
        }
        if (j + k < n && word.charAt(i + k) < word.charAt(j + k)){
            let temp = i;
            i = j;
            j = Math.max(j + 1, temp + k + 1);
        } else {
            j += k + 1;
        }
    }
    let s = word.substring(i);
    return s.length <= m ? s : s.substring(0, m);
};