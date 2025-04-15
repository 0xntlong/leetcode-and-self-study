/**
2179. Count Good Triplets in an Array
    You are given two 0-indexed arrays nums1 and nums2 of length n, both of which are permutations of [0, 1, ..., n - 1].
    A good triplet is a set of 3 distinct values which are present in increasing order by position both in nums1 and nums2. In other words, if we consider pos1v as the index of the value v in nums1 and pos2v as the index of the value v in nums2, then a good triplet will be a set (x, y, z) where 0 <= x, y, z <= n - 1, such that pos1x < pos1y < pos1z and pos2x < pos2y < pos2z.
    Return the total number of good triplets.

    Example :
    Input: nums1 = [2,0,1,3], nums2 = [0,1,2,3]
    Output: 1
    Explanation: 
    There are 4 triplets (x,y,z) such that pos1x < pos1y < pos1z. They are (2,0,1), (2,0,3), (2,1,3), and (0,1,3). 
    Out of those triplets, only the triplet (0,1,3) satisfies pos2x < pos2y < pos2z. Hence, there is only 1 good triplet.
 */


    function goodTriplets(nums1: number[], nums2: number[]): number {
        const n: number = nums1.length;
        let res: number = 0;
    
    
        const indices: number[] = new Array(n);
        for (let i = 0; i < n; i++) {
            indices[nums1[i]] = i;
        }
        for (let i = 0; i < n; i++) {
            nums2[i] = indices[nums2[i]];
        }
        for (let i = 0; i < n; i++) {
            nums1[i] = nums2[i];
        }
        class FenwickTree {
            private fenw: number[];
            private size: number;
            constructor(size: number) {
                this.size = size;
                this.fenw = new Array(size + 1).fill(0);
            }
            public update(idx: number, delta: number): void {
                idx++;
                while (idx <= this.size) {
                    this.fenw[idx] += delta;
                    idx += idx & -idx;
                }
            }
            public prefixSum(idx: number): number {
                let sum = 0;
                while (idx > 0) {
                    sum += this.fenw[idx];
                    idx -= idx & -idx;
                }
                return sum;
            }
            public countSmaller(x: number): number {
                return x > 0 ? this.prefixSum(x) : 0;
            }
        }
        const fenw = new FenwickTree(n);
        for (let i = 0; i < n; i++) {
            const num = nums1[n - 1 - i];
            const smallerCount = fenw.countSmaller(num);
            const biggerCount = i - smallerCount;
            const diffCount = num - smallerCount;
    
            res += biggerCount * diffCount;
    
            fenw.update(num, 1);
        }
        return res;
    };