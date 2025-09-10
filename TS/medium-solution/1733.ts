/**
1733. Minimum Number of People to Teach
    On a social network consisting of m users and some friendships between users, two users can communicate with each other if they know a common language.

    You are given an integer n, an array languages, and an array friendships where:

    - There are n languages numbered 1 through n.
    - languages[i] is the set of languages the i-th user knows.
    - friendships[i] = [ui, vi] denotes a friendship between the users ui and vi.
    You can choose one language and teach it to some users so that all friends can communicate with each other. Return the minimum number of users you need to teach.

    Note that friendships are not transitive, meaning if x is a friend of y and y is a friend of z, this doesn't guarantee that x is a friend of z.
    

    Example :
    Input: n = 2, languages = [[1],[2],[1,2]], friendships = [[1,2],[1,3],[2,3]]
    Output: 1
    Explanation: You can either teach user 1 the second language or user 2 the first language.
 */




function minimumTeachings(n: number, languages: number[][], friendships: number[][]): number {
    const m = languages.length;
    const dp: boolean[][] = Array.from({ length: m + 1 }, () => Array(n + 1).fill(false));
    for (let i = 0; i < m; i++) {
        for (const lang of languages[i]) 
            dp[i + 1][lang] = true;
    }

    const visited = new Set<number>(); 
    for (const [u, v] of friendships) {
        let share = false;
        for (let lang = 1; lang <= n; lang++) {
            if (dp[u][lang] && dp[v][lang]) { 
                share = true; 
                break; 
            }
        }
        if (!share) { 
            visited.add(u); 
            visited.add(v); 
        }
    }
    if (visited.size === 0) 
        return 0;

    const cnt: number[] = Array(n + 1).fill(0);
    for (const u of visited) {
        for (let lang = 1; lang <= n; lang++) {
            if (dp[u][lang]) 
                cnt[lang]++;
        }
    }
    const best = Math.max(...cnt);
    return visited.size - best;
};