/**
2226. Maximum Number of Candies Allocated to K Children
    You are given a 0-indexed integer array candies. Each element in the array denotes a pile of candies of size candies[i]. You can divide each pile into any number of sub piles, but you cannot merge two piles together.
    You are also given an integer k. You should allocate piles of candies to k children such that each child gets the same number of candies. Each child can be allocated candies from only one pile of candies and some piles of candies may go unused.
    Return the maximum number of candies each child can get.
    Example :
    Input: candies = [5,8,6], k = 3
    Output: 5
    Explanation: We can divide candies[1] into 2 piles of size 5 and 3, and candies[2] into 2 piles of size 5 and 1. We now have five piles of candies of sizes 5, 5, 3, 5, and 1. We can allocate the 3 piles of size 5 to 3 children. It can be proven that each child cannot receive more than 5 candies.
 */


    function maximumCandies(candies: number[], k: number): number {
        let total = candies.reduce((sum, c) => sum + c, 0);
        if (total < k)
            return 0;
        let left = 1, right = Math.floor(total / k);
        while (left < right){
            let mid = Math.floor((left + right + 1) / 2);
            if (Distribute(candies, mid, k)){
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    };
    
    function Distribute(candies: number[], candy: number, k: number):boolean{
        let count = candies.reduce((sum, c) => sum + Math.floor(c / candy), 0);
        return count >= k;
    }