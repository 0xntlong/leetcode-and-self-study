"""
3501. Maximize Active Section with Trade II
    You are given a binary string s of length n, where:
    '1' represents an active section.
    '0' represents an inactive section.
    You can perform at most one trade to maximize the number of active sections in s. In a trade, you:
    Convert a contiguous block of '1's that is surrounded by '0's to all '0's.
    Afterward, convert a contiguous block of '0's that is surrounded by '1's to all '1's
    Additionally, you are given a 2D array queries, where queries[i] = [li, ri] represents a substring s[li...ri].
    For each query, determine the maximum possible number of active sections in s after making the optimal trade on the substring s[li...ri].
    Return an array answer, where answer[i] is the result for queries[i].
    Note
    For each query, treat s[li...ri] as if it is augmented with a '1' at both ends, forming t = '1' + s[li...ri] + '1'. The augmented '1's do not contribute to the final count.
    The queries are independent of each other.
    
    Example 1:
    Input: s = "01", queries = [[0,1]]
    Output: [1]
    Explanation:
    Because there is no block of '1's surrounded by '0's, no valid trade is possible. The maximum number of active sections is 1.
"""


class Solution:
    def maxActiveSectionsAfterTrade(self, s: str, queries: list[list[int]]) -> list[int]:
        n = len(s)
        ones_total = s.count('1')
        
        zero_runs = []
        i = 0
        while i < n:
            if s[i] == '0':
                start = i
                while i < n and s[i] == '0':
                    i += 1
                zero_runs.append((start, i - 1))
            else:
                i += 1
                
        pairs = []
        for k in range(len(zero_runs) - 1):
            L1, R1 = zero_runs[k]
            L2, R2 = zero_runs[k+1]

            pairs.append((L1, R1, L2, R2, (R1 - L1 + 1) + (R2 - L2 + 1)))
            
        num_pairs = len(pairs)
        if num_pairs == 0:
            return [ones_total] * len(queries)
            
        K = num_pairs.bit_length()
        st = [[0] * K for _ in range(num_pairs)]
        for j in range(num_pairs):
            st[j][0] = pairs[j][4]
            
        for j in range(1, K):
            for idx in range(num_pairs - (1 << j) + 1):
                st[idx][j] = max(st[idx][j-1], st[idx + (1 << (j-1))][j-1])
                
        def query_st(L, R):
            if L > R:
                return 0
            j = (R - L + 1).bit_length() - 1
            return max(st[L][j], st[R - (1 << j) + 1][j])
            

        R1_list = [p[1] for p in pairs]
        L2_list = [p[2] for p in pairs] 
        
        ans = []

        for l, r in queries:
            first_k = bisect.bisect_left(R1_list, l)
            last_k = bisect.bisect_right(L2_list, r) - 1

            if first_k > last_k:
                ans.append(ones_total)
                continue
                
            best_gain = 0
            
            if first_k == last_k:
                L1, R1, L2, R2, _ = pairs[first_k]
                gain = (R1 - max(L1, l) + 1) + (min(R2, r) - L2 + 1)
                best_gain = max(best_gain, gain)
            else:
                L1, R1, L2, R2, _ = pairs[first_k]
                gain1 = (R1 - max(L1, l) + 1) + (min(R2, r) - L2 + 1)
                best_gain = max(best_gain, gain1)
                
                L1, R1, L2, R2, _ = pairs[last_k]
                gain2 = (R1 - max(L1, l) + 1) + (min(R2, r) - L2 + 1)
                best_gain = max(best_gain, gain2)

                if first_k + 1 <= last_k - 1:
                    best_gain = max(best_gain, query_st(first_k + 1, last_k - 1))
                    
            ans.append(ones_total + best_gain)
            
        return ans