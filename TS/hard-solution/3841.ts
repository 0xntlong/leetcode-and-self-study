/**
3841. Palindromic Path Queries in a Tree
    You are given an undirected tree with n nodes labeled 0 to n - 1. This is represented by a 2D array edges of length n - 1, where edges[i] = [ui, vi] indicates an undirected edge between nodes ui and vi.
    You are also given a string s of length n consisting of lowercase English letters, where s[i] represents the character assigned to node i.
    You are also given a string array queries, where each queries[i] is either:
    "update ui c": Change the character at node ui to c. Formally, update s[ui] = c.
    "query ui vi": Determine whether the string formed by the characters on the unique path from ui to vi (inclusive) can be rearranged into a palindrome.
    Return a boolean array answer, where answer[j] is true if the jth query of type "query ui vi"​​​​​​​ can be rearranged into a palindrome, and false otherwise.

    Example :
    Input: n = 3, edges = [[0,1],[1,2]], s = "aac", queries = ["query 0 2","update 1 b","query 0 2"]
    Output: [true,false]
    Explanation:
    "query 0 2": Path 0 → 1 → 2 gives "aac", which can be rearranged to form "aca", a palindrome. Thus, answer[0] = true.
    "update 1 b": Update node 1 to 'b', now s = "abc".
    "query 0 2": Path characters are "abc", which cannot be rearranged to form a palindrome. Thus, answer[1] = false.
    Thus, answer = [true, false].
 */



function palindromePath(n: number, edges: number[][], s: string, queries: string[]): boolean[] {
    const g: number[][] = Array.from({ length: n }, () => []);

    for (const [u, v] of edges) {
        g[u].push(v);
        g[v].push(u);
    }

    const parent = new Int32Array(n).fill(-1);
    const depth = new Int32Array(n);
    const order: number[] = [0];
    parent[0] = 0;

    for (let i = 0; i < order.length; i++) {
        const u = order[i];

        for (const v of g[u]) {
            if (v !== parent[u]) {
                parent[v] = u;
                depth[v] = depth[u] + 1;
                order.push(v);
            }
        }
    }

    const size = new Int32Array(n).fill(1);
    const heavy = new Int32Array(n).fill(-1);

    for (let i = n - 1; i > 0; i--) {
        const u = order[i];
        const p = parent[u];

        size[p] += size[u];

        if (heavy[p] === -1 || size[u] > size[heavy[p]]) {
            heavy[p] = u;
        }
    }

    const head = new Int32Array(n);
    const pos = new Int32Array(n);
    const stack: number[] = [0];
    let cur = 0;

    while (stack.length > 0) {
        let u = stack.pop()!;
        const h = u;

        while (u !== -1) {
            head[u] = h;
            pos[u] = cur++;

            for (const v of g[u]) {
                if (v !== parent[u] && v !== heavy[u]) {
                    stack.push(v);
                }
            }

            u = heavy[u];
        }
    }

    let size2 = 1;
    while (size2 < n) size2 <<= 1;

    const seg = new Int32Array(2 * size2);

    for (let u = 0; u < n; u++) {
        seg[size2 + pos[u]] = 1 << (s.charCodeAt(u) - 97);
    }

    for (let i = size2 - 1; i > 0; i--) {
        seg[i] = seg[i * 2] ^ seg[i * 2 + 1];
    }

    function update(p: number, value: number): void {
        p += size2;
        seg[p] = value;

        for (p >>= 1; p > 0; p >>= 1) {
            seg[p] = seg[p * 2] ^ seg[p * 2 + 1];
        }
    }

    function rangeQuery(l: number, r: number): number {
        l += size2;
        r += size2;
        let res = 0;

        while (l <= r) {
            if (l & 1) res ^= seg[l++];
            if (!(r & 1)) res ^= seg[r--];

            l >>= 1;
            r >>= 1;
        }

        return res;
    }

    function pathQuery(u: number, v: number): number {
        let res = 0;

        while (head[u] !== head[v]) {
            if (depth[head[u]] < depth[head[v]]) {
                [u, v] = [v, u];
            }

            res ^= rangeQuery(pos[head[u]], pos[u]);
            u = parent[head[u]];
        }

        if (depth[u] > depth[v]) {
            [u, v] = [v, u];
        }

        return res ^ rangeQuery(pos[u], pos[v]);
    }

    const ans: boolean[] = [];

    for (const q of queries) {
        const parts = q.trim().split(/\s+/);
        const u = Number(parts[1]);

        if (parts[0] === "update") {
            update(pos[u], 1 << (parts[2].charCodeAt(0) - 97));
        } else {
            const v = Number(parts[2]);
            const mask = pathQuery(u, v);
            ans.push((mask & (mask - 1)) === 0);
        }
    }

    return ans;
};