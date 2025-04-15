/*
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

class Fenwick{
    private:
        vector<long long> fenw;
        int n;
    public:
        Fenwick(int n) : n(n), fenw(n + 1, 0){}
        void update(int idx, long long val){
            idx++;
            while (idx <= n){
                fenw[idx] += val;
                idx += idx & -idx;
            }
        }
        long long query(int idx) const{
            long long sum = 0;
            idx++;
            while (idx > 0){
                sum += fenw[idx];
                idx -= idx & -idx;
            }
            return sum;
        }
        long long countLess(int idx) const{
            return (idx > 0) ? query(idx - 1) : 0;
        }
    };
    
    class Solution {
    public:
        long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
            int n = nums1.size();
            long long res = 0;
            vector<int> idx_map(n);
            for (int i = 0; i < n; i++){
                idx_map[nums1[i]] = i;
            }
            for (int i = 0; i < n; i++){
                nums2[i] = idx_map[nums2[i]];
            }
            Fenwick fenw(n);
            for (int i = 0; i < n; i++){
                int num = nums2[n - 1 - i];
                long long smallerCount = fenw.countLess(num);
                long long biggerCount = i - smallerCount;
                long long diffCount = num - smallerCount;
                res += biggerCount * diffCount;
                fenw.update(num, 1);
            }
            return res;
        }
    };