/**
3863. Minimum Operations to Sort a String
    You are given a string s consisting of lowercase English letters.
    In one operation, you can select any substring of s that is not the entire string and sort it in non-descending alphabetical order.
    Return the minimum number of operations required to make s sorted in non-descending order. If it is not possible, return -1.

    Example :
    Input: s = "dog"
    Output: 1
    Explanation:
    Sort substring "og" to "go".
    Now, s = "dgo", which is sorted in ascending order. Thus, the answer is 1.
 */



function minOperations(s: string): number {
    const n = s.length;

    if (n === 2 && s[0] > s[1]) {
        return -1;
    }

    let sorted = true;

    for (let i = 0; i < n - 1; i++) {
        if (s[i] > s[i + 1]) {
            sorted = false;
            break;
        }
    }

    if (sorted) {
        return 0;
    }

    let mn: string = s[1];
    let mx: string = s[1];

    for (let i = 1; i < n - 1; i++) {
        if (s[i] < mn) {
            mn = s[i];
        }

        if (s[i] > mx) {
            mx = s[i];
        }
    }

    const left: string = s[0];
    const right: string = s[n - 1];

    if ((left <= right && left <= mn) ||
        (right >= left && right >= mx)) {
        return 1;
    } else if (right >= mn || left <= mx) {
        return 2;
    } else {
        return 3;
    }
};