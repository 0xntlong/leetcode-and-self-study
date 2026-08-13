/**
2213. Longest Substring of One Repeating Character
    You are given a 0-indexed string s. You are also given a 0-indexed string queryCharacters of length k and a 0-indexed array of integer indices queryIndices of length k, both of which are used to describe k queries.
    The ith query updates the character in s at index queryIndices[i] to the character queryCharacters[i].
    Return an array lengths of length k where lengths[i] is the length of the longest substring of s consisting of only one repeating character after the ith query is performed.
    Example :
    Input: s = "babacc", queryCharacters = "bcb", queryIndices = [1,3,3]
    Output: [3,3,4]
    Explanation: 
    - 1st query updates s = "bbbacc". The longest substring consisting of one repeating character is "bbb" with length 3.
    - 2nd query updates s = "bbbccc". 
    The longest substring consisting of one repeating character can be "bbb" or "ccc" with length 3.
    - 3rd query updates s = "bbbbcc". The longest substring consisting of one repeating character is "bbbb" with length 4.
    Thus, we return [3,3,4].
 */



class Solution {
private:
    struct Node {char leftChar; char rightChar; int length; int prefix; int suffix; int best;
};

    vector<Node> tree;

    Node mergeNodes(const Node& left, const Node& right) {
        Node res;

        res.leftChar = left.leftChar;
        res.rightChar = right.rightChar;
        res.length = left.length + right.length;

        res.prefix = left.prefix;

        if (
            left.rightChar == right.leftChar &&
            left.prefix == left.length
        ) {
            res.prefix = left.length + right.prefix;
        }

        res.suffix = right.suffix;

        if (
            left.rightChar == right.leftChar &&
            right.suffix == right.length
        ) {
            res.suffix = right.length + left.suffix;
        }

        res.best = max(left.best, right.best);

        if (left.rightChar == right.leftChar) {
            res.best = max(
                res.best,
                left.suffix + right.prefix
            );
        }

        return res;
    }

    void build( int node, int start, int end, const string& s
    ) {
        if (start == end) {
            tree[node] = {s[start], s[start], 1, 1, 1, 1};
            return;
        }

        int mid = (start + end) / 2;

        build(node * 2, start, mid, s);
        build(node * 2 + 1, mid + 1, end, s);

        tree[node] = mergeNodes(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

    void update( int node, int start, int end, int index, char ch ) {
        if (start == end) {
            tree[node] = {ch, ch, 1, 1, 1, 1};
            return;
        }

        int mid = (start + end) / 2;

        if (index <= mid) {
            update(node * 2, start, mid, index, ch);
        } else {
            update(node * 2 + 1, mid + 1, end, index, ch);
        }

        tree[node] = mergeNodes(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

public:
    vector<int> longestRepeating( string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, s);
        vector<int> answer;

        for (int i = 0; i < queryIndices.size(); i++) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            answer.push_back(tree[1].best);
        }

        return answer;
    }
};