/**
2685. Count the Number of Complete Components
    You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.
    Return the number of complete connected components of the graph.
    A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.
    A connected component is said to be complete if there exists an edge between every pair of its vertices.

    Example :
    Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
    Output: 3
    Explanation: From the picture above, one can see that all of the components of this graph are complete.
 */

    function countCompleteComponents(n: number, edges: number[][]): number {
        const X : number[][] = new Array(n).fill([]).map(() =>[]);
        for (let edge of edges){
            const[u, v] = edge;
            X[u].push(v);
            X[v].push(u);
        }
        const visited: boolean[] = new Array(n).fill(false);
        let res = 0;
        for (let i = 0; i < n; i++){
            if (visited[i])
                continue;
            const bfs: number[] = [i];
            visited[i] = true;
            let bfsSize = 0;
            for (let j = 0; j < bfs.length; j++){
                const curr = bfs[j];
                for (let k of X[curr]){
                    if (!visited[k]){
                        bfs.push(k);
                        visited[k] = true;
                    }
                }
            }
            let complete =true;
            for (let j of bfs){
                if (X[j].length !== bfs.length - 1){
                    complete = false;
                    break;
                }
            }
            if (complete){
                res++;
            }
        }
        return res;
    };