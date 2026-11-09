/**
1606. Find Servers That Handled Most Number of Requests
    You have k servers numbered from 0 to k-1 that are being used to handle multiple requests simultaneously. Each server has infinite computational capacity but cannot handle more than one request at a time. The requests are assigned to servers according to a specific algorithm:
    The ith (0-indexed) request arrives.
    If all servers are busy, the request is dropped (not handled at all).
    If the (i % k)th server is available, assign the request to that server.
    Otherwise, assign the request to the next available server (wrapping around the list of servers and starting from 0 if necessary). For example, if the ith server is busy, try to assign the request to the (i+1)th server, then the (i+2)th server, and so on.
    You are given a strictly increasing array arrival of positive integers, where arrival[i] represents the arrival time of the ith request, and another array load, where load[i] represents the load of the ith request (the time it takes to complete). Your goal is to find the busiest server(s). A server is considered busiest if it handled the most number of requests successfully among all the servers.
    Return a list containing the IDs (0-indexed) of the busiest server(s). You may return the IDs in any order.
    Example :
    Input: k = 3, arrival = [1,2,3,4,5], load = [5,2,3,3,3] 
    Output: [1] 
    Explanation: 
    All of the servers start out available.
    The first 3 requests are handled by the first 3 servers in order.
    Request 3 comes in. Server 0 is busy, so it's assigned to the next available server, which is 1.
    Request 4 comes in. It cannot be handled since all servers are busy, so it is dropped.
    Servers 0 and 2 handled one request each, while server 1 handled two requests. Hence server 1 is the busiest server.
 */



function busiestServers(k: number, arrival: number[], load: number[]): number[] {
    class MinHeap {
        private data: number[][] = [];

        size(): number {
            return this.data.length;
        }

        peek(): number[] {
            return this.data[0];
        }

        push(value: number[]): void {
            const a = this.data;
            a.push(value);

            let i = a.length - 1;

            while (i > 0) {
                const p = Math.floor((i - 1) / 2);
                if (a[p][0] <= a[i][0]) break;

                [a[p], a[i]] = [a[i], a[p]];
                i = p;
            }
        }

        pop(): number[] {
            const a = this.data;
            const result = a[0];
            const last = a.pop()!;

            if (a.length === 0) return result;

            a[0] = last;
            let i = 0;

            while (true) {
                const l = 2 * i + 1;
                const r = 2 * i + 2;
                let best = i;

                if (l < a.length && a[l][0] < a[best][0])
                    best = l;

                if (r < a.length && a[r][0] < a[best][0])
                    best = r;

                if (best === i) break;

                [a[i], a[best]] = [a[best], a[i]];
                i = best;
            }

            return result;
        }
    }

    class Fenwick {
        private tree: number[];

        constructor(private n: number) {
            this.tree = new Array(n + 1).fill(0);
        }

        update(i: number, delta: number): void {
            for (i++; i <= this.n; i += i & -i) {
                this.tree[i] += delta;
            }
        }

        query(i: number): number {
            let sum = 0;

            for (i++; i > 0; i -= i & -i) {
                sum += this.tree[i];
            }

            return sum;
        }

        kth(kth: number): number {
            let idx = 0;
            let bit = 1;

            while (bit * 2 <= this.n) bit *= 2;

            for (; bit > 0; bit = Math.floor(bit / 2)) {
                const next = idx + bit;

                if (next <= this.n && this.tree[next] < kth) {
                    idx = next;
                    kth -= this.tree[next];
                }
            }

            return idx;
        }
    }

    const heap = new MinHeap();
    const free = new Fenwick(k);
    const server: number[] = new Array(k).fill(0);

    for (let i = 0; i < k; i++) {
        free.update(i, 1);
    }

    let available = k;

    for (let i = 0; i < arrival.length; i++) {
        const arr = arrival[i];
        const l = load[i];

        while (heap.size() > 0 && heap.peek()[0] <= arr) {
            const [time, s] = heap.pop();
            free.update(s, 1);
            available++;
        }

        if (available === 0) continue;

        const start = i % k;
        const before = start > 0 ? free.query(start - 1) : 0;

        const rank = before < available ? before + 1 : 1;
        const s = free.kth(rank);

        free.update(s, -1);
        available--;

        heap.push([arr + l, s]);
        server[s]++;
    }

    const max_ = Math.max(...server);
    const res: number[] = [];

    for (let i = 0; i < k; i++) {
        if (server[i] === max_) {
            res.push(i);
        }
    }

    return res;
};