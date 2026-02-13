/**
3714. Longest Balanced Substring II
    You are given a string s consisting only of the characters 'a', 'b', and 'c'.
    A substring of s is called balanced if all distinct characters in the substring appear the same number of times.
    Return the length of the longest balanced substring of s.
    Example :
    Input: s = "abbac"
    Output: 4
    Explanation:
    The longest balanced substring is "abba" because both distinct characters 'a' and 'b' each appear exactly 2 times.
 */


function longestBalanced(s: string): number {
  const n = s.length;
  let ans = 0;
  for (let i = 0; i < n; ) {
    const start = i++;
    while (i < n && s[i] === s[i - 1]) 
        i++;
    ans = Math.max(ans, i - start);
  }


  ans = Math.max(ans, twoChars(s, "a", "b"));
  ans = Math.max(ans, twoChars(s, "a", "c"));
  ans = Math.max(ans, twoChars(s, "b", "c"));

  const pos = new Map<string, number>();
  pos.set(key(0, 0), -1);

  let ca = 0, cb = 0, cc = 0;
  for (let i = 0; i < n; i++) {
    const ch = s[i];
    if (ch === "a") 
        ca++;
    else if (ch === "b") 
        cb++;
    else if (ch === "c") 
        cc++;

    const d1 = ca - cb;
    const d2 = cb - cc;
    const k = key(d1, d2);

    const prev = pos.get(k);
    if (prev !== undefined) 
        ans = Math.max(ans, i - prev);
    else pos.set(k, i);
  }

  return ans;
}

function twoChars(s: string, x: string, y: string): number {
  const n = s.length;
  let best = 0;

  const INT_MAX = 2147483647;
  const first = new Int32Array(2 * n + 1);
  first.fill(INT_MAX);

  const touched = new Int32Array(2 * n + 1);
  let touchedSz = 0;

  let i = 0;
  while (i < n) {
    const segStart = i;

    first[n] = segStart - 1;
    touched[touchedSz++] = n;

    let d = 0;
    while (i < n && (s[i] === x || s[i] === y)) {
      d += (s[i] === x) ? 1 : -1;
      const idx = d + n;

      if (first[idx] !== INT_MAX) best = Math.max(best, i - first[idx]);
      else {
        first[idx] = i;
        touched[touchedSz++] = idx;
      }
      i++;
    }

    for (let k = 0; k < touchedSz; k++) first[touched[k]] = INT_MAX;
    touchedSz = 0;

    i++; 
  }

  return best;
}

function key(d1: number, d2: number): string {
  return `${d1},${d2}`;
}