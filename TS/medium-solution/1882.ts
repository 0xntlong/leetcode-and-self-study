/**
1882. Process Tasks Using Servers
    You are given two 0-indexed integer arrays servers and tasks of lengths n and m respectively. servers[i] is the weight of the i th server, and tasks[j] is the time needed to process the j th task in seconds.

    Tasks are assigned to the servers using a task queue. Initially, all servers are free, and the queue is empty.

    At second j, the jth task is inserted into the queue (starting with the 0th task being inserted at second 0). As long as there are free servers and the queue is not empty, the task in the front of the queue will be assigned to a free server with the smallest weight, and in case of a tie, it is assigned to a free server with the smallest index.

    If there are no free servers and the queue is not empty, we wait until a server becomes free and immediately assign the next task. If multiple servers become free at the same time, then multiple tasks from the queue will be assigned in order of insertion following the weight and index priorities above.

    A server that is assigned task j at second t will be free again at second t + tasks[j].

    Build an array ans of length m, where ans[j] is the index of the server the j th task will be assigned to.

    Return the array ans

    

    Example 1:

    Input: servers = [3,3,2], tasks = [1,2,3,2,1,2]
    Output: [2,2,0,2,1,2]
    Explanation: Events in chronological order go as follows:
    - At second 0, task 0 is added and processed using server 2 until second 1.
    - At second 1, server 2 becomes free. Task 1 is added and processed using server 2 until second 3.
    - At second 2, task 2 is added and processed using server 0 until second 5.
    - At second 3, server 2 becomes free. Task 3 is added and processed using server 2 until second 5.
    - At second 4, task 4 is added and processed using server 1 until second 5.
    - At second 5, all servers become free. Task 5 is added and processed using server 2 until second 7.
 */


function assignTasks(servers: number[], tasks: number[]): number[] {
    class MinHeap {
        private data: number[][] = [];

        constructor(
            private compare: (a: number[], b: number[]) => number
        ) {}

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
                if (this.compare(a[i], a[p]) >= 0) break;

                [a[i], a[p]] = [a[p], a[i]];
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

                if (l < a.length && this.compare(a[l], a[best]) < 0)
                    best = l;

                if (r < a.length && this.compare(a[r], a[best]) < 0)
                    best = r;

                if (best === i) break;

                [a[i], a[best]] = [a[best], a[i]];
                i = best;
            }

            return result;
        }
    }

    const heapsmol = new MinHeap((a, b) =>
        a[0] - b[0] || a[1] - b[1]
    );

    const heaplarge = new MinHeap((a, b) =>
        a[0] - b[0] || a[1] - b[1] || a[2] - b[2]
    );

    for (let i = 0; i < servers.length; i++) {
        heapsmol.push([servers[i], i]);
    }

    const ans: number[] = [];

    for (let i = 0; i < tasks.length; i++) {
        while (heaplarge.size() > 0 && heaplarge.peek()[0] <= i) {
            const [time, weight, index] = heaplarge.pop();
            heapsmol.push([weight, index]);
        }

        if (heapsmol.size() > 0) {
            const [weight, index] = heapsmol.pop();
            ans.push(index);
            heaplarge.push([i + tasks[i], weight, index]);
        } else {
            const [time, weight, index] = heaplarge.pop();
            ans.push(index);
            heaplarge.push([time + tasks[i], weight, index]);
        }
    }
    return ans;

};