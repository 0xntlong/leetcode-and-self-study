/**
2452. Words Within Two Edits of Dictionary
    You are given two string arrays, queries and dictionary. All words in each array comprise of lowercase English letters and have the same length.

    In one edit you can take a word from queries, and change any letter in it to any other letter. Find all words from queries that, after a maximum of two edits, equal some word from dictionary.

    Return a list of all words from queries, that match with some word from dictionary after a maximum of two edits. Return the words in the same order they appear in queries.

    Example :

    Input: queries = ["word","note","ants","wood"], dictionary = ["wood","joke","moat"]
    Output: ["word","note","wood"]
    Explanation:
    - Changing the 'r' in "word" to 'o' allows it to equal the dictionary word "wood".
    - Changing the 'n' to 'j' and the 't' to 'k' in "note" changes it to "joke".
    - It would take more than 2 edits for "ants" to equal a dictionary word.
    - "wood" can remain unchanged (0 edits) and match the corresponding dictionary word.
    Thus, we return ["word","note","wood"].
 */

function twoEditWords(queries: string[], dictionary: string[]): string[] {
    const res: string[] = [];
    const word_len = queries[0].length;
    for (const q of queries) {
        for (const d of dictionary) {
            let diff = 0;
            for (let j = 0; j < word_len; j++) {
                if (q[j] !== d[j]) 
                    diff++;
                if (diff > 2) 
                    break;
            }
            if (diff <= 2) {
                res.push(q);
                break;
            }
        }
    }
    return res;
};