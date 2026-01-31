/**
744. Find Smallest Letter Greater Than Target
    You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.
    Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.

    Example :
    Input: letters = ["c","f","j"], target = "a"
    Output: "c"
    Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'.
 */



function nextGreatestLetter(letters: string[], target: string): string {
    const n = letters.length;
    let low = 0, high = n - 1;
    let min_letter = 'z';
    let count = 0;

    while (low <= high) {
        const mid = (low + high) >> 1;
        if (letters[mid] > target) {
            if (letters[mid] < min_letter) 
                min_letter = letters[mid];
            high = mid - 1;
            count = 1;
        } else {
            low = mid + 1;
        }
    }
    if (count === 0) 
        return letters[0];
    return min_letter;
};