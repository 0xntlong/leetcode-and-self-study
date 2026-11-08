/**
2747. Count Zero Request Servers
    You are given an integer n denoting the total number of servers and a 2D 0-indexed integer array logs, where logs[i] = [server_id, time] denotes that the server with id server_id received a request at time time.
    You are also given an integer x and a 0-indexed integer array queries.
    Return a 0-indexed integer array arr of length queries.length where arr[i] represents the number of servers that did not receive any requests during the time interval [queries[i] - x, queries[i]].
    Note that the time intervals are inclusive.
    Example :
    Input: n = 3, logs = [[1,3],[2,6],[1,5]], x = 5, queries = [10,11]
    Output: [1,2]
    Explanation: 
    For queries[0]: The servers with ids 1 and 2 get requests in the duration of [5, 10]. Hence, only server 3 gets zero requests.
    For queries[1]: Only the server with id 2 gets a request in duration of [6,11]. Hence, the servers with ids 1 and 3 are the only servers that do not receive any requests during that time period.
 */


function countServers1(n: number, logs: number[][], x: number, queries: number[]): number[] {
    logs.sort((a, b) => a[1] - b[1]);

    const orderedQueries: number[][] = queries.map((q, i) => [q, i]);
    orderedQueries.sort((a, b) => a[0] - b[0]);

    const frequency: number[] = new Array(n + 1).fill(0);
    const answer: number[] = new Array(queries.length).fill(0);

    let active = 0, left = 0, right = 0;

    for (const [q, originalIndex] of orderedQueries) {
        const lower = q - x;

        while (right < logs.length && logs[right][1] <= q) {
            const server = logs[right][0];
            if (frequency[server] === 0) {
                active++;
            }
            frequency[server]++;
            right++;
        }

        while (left < right && logs[left][1] < lower) {
            const server = logs[left][0];
            frequency[server]--;
            if (frequency[server] === 0) {
                active--;
            }
            left++;
        }

        answer[originalIndex] = n - active;
    }

    return answer;
};