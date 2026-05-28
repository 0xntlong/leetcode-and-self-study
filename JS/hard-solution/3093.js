/**
3093. Longest Common Suffix Queries
    You are given two arrays of strings wordsContainer and wordsQuery.
    For each wordsQuery[i], you need to find a string from wordsContainer that has the longest common suffix with wordsQuery[i]. If there are two or more strings in wordsContainer that share the longest common suffix, find the string that is the smallest in length. If there are two or more such strings that have the same smallest length, find the one that occurred earlier in wordsContainer.
    Return an array of integers ans, where ans[i] is the index of the string in wordsContainer that has the longest common suffix with wordsQuery[i].
    
    Example :
    Input: wordsContainer = ["abcd","bcd","xbcd"], wordsQuery = ["cd","bcd","xyz"]
    Output: [1,1,1]
    Explanation:

    Let's look at each wordsQuery[i] separately:

    For wordsQuery[0] = "cd", strings from wordsContainer that share the longest common suffix "cd" are at indices 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.
    For wordsQuery[1] = "bcd", strings from wordsContainer that share the longest common suffix "bcd" are at indices 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.
    For wordsQuery[2] = "xyz", there is no string from wordsContainer that shares a common suffix. Hence the longest common suffix is "", that is shared with strings at index 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.
 */



/**
 * @param {string[]} wordsContainer
 * @param {string[]} wordsQuery
 * @return {number[]}
 */
var stringIndices = function(wordsContainer, wordsQuery) {
    const root = { children: {}, best: -1, len: Infinity };
    let minLenIdx = 0;
    wordsContainer.forEach((word, idx) => {
        if (word.length < wordsContainer[minLenIdx].length) 
            minLenIdx = idx;
        
        let curr = root;
        for (let i = word.length - 1; i >= 0; i--) {
            const char = word[i];
            if (!curr.children[char]) 
                curr.children[char] = { children: {}, best: idx, len: word.length };
            curr = curr.children[char];
            if (word.length < curr.len) { 
                curr.best = idx; curr.len = word.length; 
            }
        }
    });

    return wordsQuery.map(word => {
        let curr = root, lastBest = -1;
        for (let i = word.length - 1; i >= 0; i--) {
            if (!curr.children[word[i]]) 
                break;
            curr = curr.children[word[i]];
            lastBest = curr.best;
        }
        return lastBest === -1 ? minLenIdx : lastBest;
    });
};