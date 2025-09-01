/*
1792. Maximum Average Pass Ratio
    There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.
    You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.
    The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.
    Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted.

    Example :
    Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
    Output: 0.78333
    Explanation: You can assign the two extra students to the first class. The average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.
*/



class PriorityQueue<T> {
    private heap: T[];
    private comparator: (a: T, b: T) => number;

    constructor(comparator: (a: T, b: T) => number) {
        this.heap = [];
        this.comparator = comparator;
    }

    enqueue(item: T) {
        this.heap.push(item);
        this._siftUp();
    }

    dequeue(): T | undefined {
        if (this.size() === 0) return undefined;
        const top = this.heap[0];
        const last = this.heap.pop()!;
        if (this.size() > 0) {
            this.heap[0] = last;
            this._siftDown();
        }
        return top;
    }

    size(): number {
        return this.heap.length;
    }

    private _siftUp() {
        let nodeIdx = this.heap.length - 1;
        while (nodeIdx > 0) {
            const parentIdx = Math.floor((nodeIdx - 1) / 2);
            if (this.comparator(this.heap[nodeIdx], this.heap[parentIdx]) > 0) {
                [this.heap[nodeIdx], this.heap[parentIdx]] = [this.heap[parentIdx], this.heap[nodeIdx]];
                nodeIdx = parentIdx;
            } else {
                break;
            }
        }
    }

    private _siftDown() {
        let nodeIdx = 0;
        const length = this.heap.length;
        while (true) {
            let leftIdx = 2 * nodeIdx + 1;
            let rightIdx = 2 * nodeIdx + 2;
            let swapIdx = nodeIdx;

            if (leftIdx < length && this.comparator(this.heap[leftIdx], this.heap[swapIdx]) > 0) {
                swapIdx = leftIdx;
            }
            if (rightIdx < length && this.comparator(this.heap[rightIdx], this.heap[swapIdx]) > 0) {
                swapIdx = rightIdx;
            }
            if (swapIdx === nodeIdx) break;
            [this.heap[nodeIdx], this.heap[swapIdx]] = [this.heap[swapIdx], this.heap[nodeIdx]];
            nodeIdx = swapIdx;
        }
    }
}

function maxAverageRatio(classes: number[][], extraStudents: number): number {
    const n: number = classes.length;
    
    const pq = new PriorityQueue<[number, number]>((a, b) => b[0] - a[0]);

    for (let i = 0; i < n; i++) {
        const [pass, total] = classes[i];
        const currentAverage = pass / total;
        const newAverage = (pass + 1) / (total + 1);
        const gain = newAverage - currentAverage;
        pq.enqueue([gain, i]);
    }

    while (extraStudents--) {
        const [currentGain, currentClass] = pq.dequeue() as [number, number];

        classes[currentClass][0]++;
        classes[currentClass][1]++;

        const newAverage = classes[currentClass][0] / classes[currentClass][1];
        const nextAverage = (classes[currentClass][0] + 1) / (classes[currentClass][1] + 1);

        const gain = nextAverage - newAverage;
        pq.enqueue([gain, currentClass]);
    }

    let result = 0;
    for (let i = 0; i < n; i++) {
        result += classes[i][0] / classes[i][1];
    }

    return result / n;
};