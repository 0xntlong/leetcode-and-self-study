/**
3479. Fruits Into Baskets III
    You are given two arrays of integers, fruits and baskets, each of length n, where fruits[i] represents the quantity of the ith type of fruit, and baskets[j] represents the capacity of the jth basket.
    From left to right, place the fruits according to these rules:
    Each fruit type must be placed in the leftmost available basket with a capacity greater than or equal to the quantity of that fruit type.
    Each basket can hold only one type of fruit.
    If a fruit type cannot be placed in any basket, it remains unplaced.
    Return the number of fruit types that remain unplaced after all possible allocations are made.

    Example :
    Input: fruits = [4,2,5], baskets = [3,5,4]
    Output: 1
    Explanation:
    fruits[0] = 4 is placed in baskets[1] = 5.
    fruits[1] = 2 is placed in baskets[0] = 3.
    fruits[2] = 5 cannot be placed in baskets[2] = 4.
    Since one fruit type remains unplaced, we return 1.
 */



class SegmentTree {
    seg: number[];
    n: number;

    constructor(data: number[]) {
        this.n = data.length;
        this.seg = new Array(4 * this.n).fill(-1);
        this.build(data, 1, 0, this.n - 1);
    }

    build(data: number[], idx: number, l: number, r: number): void {
        if (l === r) {
            this.seg[idx] = data[l];
        } else {
            const m = Math.floor((l + r) / 2);
            this.build(data, 2 * idx, l, m);
            this.build(data, 2 * idx + 1, m + 1, r);
            this.seg[idx] = Math.max(this.seg[2 * idx], this.seg[2 * idx + 1]);
        }
    }

    search(idx: number, l: number, r: number, k: number): number {
        if (this.seg[idx] < k) return -1;
        if (l === r) {
            this.seg[idx] = -1;
            return l;
        }
        const m = Math.floor((l + r) / 2);
        let pos: number;
        if (this.seg[2 * idx] >= k)
            pos = this.search(2 * idx, l, m, k);
        else
            pos = this.search(2 * idx + 1, m + 1, r, k);
        this.seg[idx] = Math.max(this.seg[2 * idx], this.seg[2 * idx + 1]);
        return pos;
    }
}

function numOfUnplacedFruits(fruits: number[], baskets: number[]): number {
    const n = fruits.length;
    const seg = new SegmentTree(baskets);
    let unplaced = 0;
    for (const fruit of fruits) {
        if (seg.search(1, 0, n - 1, fruit) === -1)
            unplaced++;
    }
    return unplaced;
}