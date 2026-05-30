/**
3161. Block Placement Queries
    There exists an infinite number line, with its origin at 0 and extending towards the positive x-axis.
    You are given a 2D array queries, which contains two types of queries:
    For a query of type 1, queries[i] = [1, x]. Build an obstacle at distance x from the origin. It is guaranteed that there is no obstacle at distance x when the query is asked.
    For a query of type 2, queries[i] = [2, x, sz]. Check if it is possible to place a block of size sz anywhere in the range [0, x] on the line, such that the block entirely lies in the range [0, x]. A block cannot be placed if it intersects with any obstacle, but it may touch it. Note that you do not actually place the block. Queries are separate.
    Return a boolean array results, where results[i] is true if you can place the block specified in the ith query of type 2, and false otherwise.
    Example :
    Input: queries = [[1,2],[2,3,3],[2,3,1],[2,2,2]]
    Output: [false,true,true]
    Explanation:
    For query 0, place an obstacle at x = 2. A block of size at most 2 can be placed before x = 3.
 */


/**
 * @param {number[][]} queries
 * @return {boolean[]}
 */
var getResults = function(queries) {
    let maxX = 0;
    for (const q of queries) {
        maxX = Math.max(maxX, q[1]);
    }
    
    let n = 1;
    while (n <= maxX + 1) n *= 2;
    const tree = new Int32Array(2 * n);
    
    const update = (i, val) => {
        for (tree[i += n] = val; i > 1; i >>= 1) {
            tree[i >> 1] = Math.max(tree[i], tree[i ^ 1]);
        }
    };
    
    const query = (r) => {
        let res = 0;
        for (let l = n, r_idx = r + n + 1; l < r_idx; l >>= 1, r_idx >>= 1) {
            if (l & 1) 
                res = Math.max(res, tree[l++]);
            if (r_idx & 1) 
                res = Math.max(res, tree[--r_idx]);
        }
        return res;
    };
    
    const obstacles = [0];
    const res = [];
    
    for (const q of queries) {
        const type = q[0];
        const x = q[1];
        let l = 0, r = obstacles.length;
        while (l < r) {
            const mid = (l + r) >> 1;
            if (obstacles[mid] > x) 
                r = mid;
            else l = mid + 1;
        }
        const idx = l;
        
        if (type === 1) {
            const prev = obstacles[idx - 1];
            const nxt = idx < obstacles.length ? obstacles[idx] : -1;
            
            update(x, x - prev);
            if (nxt !== -1) {
                update(nxt, nxt - x);
            }
            obstacles.splice(idx, 0, x);
        } else {
            const sz = q[2];
            const prev = obstacles[idx - 1];
            const mx = Math.max(x - prev, query(prev));
            res.push(sz <= mx);
        }
    }
    
    return res;
};