/**
1096. Brace Expansion II
Under the grammar given below, strings can represent a set of lowercase words. Let R(expr) denote the set of words the expression represents.
    The grammar can best be understood through simple examples:
    Single letters represent a singleton set containing that word.
    R("a") = {"a"}
    R("w") = {"w"}
    When we take a comma-delimited list of two or more expressions, we take the union of possibilities.
    R("{a,b,c}") = {"a","b","c"}
    R("{{a,b},{b,c}}") = {"a","b","c"} (notice the final set only contains each word at most once)
    When we concatenate two expressions, we take the set of possible concatenations between two words where the first word comes from the first expression and the second word comes from the second expression.
    R("{a,b}{c,d}") = {"ac","ad","bc","bd"}
    R("a{b,c}{d,e}f{g,h}") = {"abdfg", "abdfh", "abefg", "abefh", "acdfg", "acdfh", "acefg", "acefh"}
    Formally, the three rules for our grammar:
    For every lowercase letter x, we have R(x) = {x}.
    For expressions e1, e2, ... , ek with k >= 2, we have R({e1, e2, ...}) = R(e1) ∪ R(e2) ∪ ...
    For expressions e1 and e2, we have R(e1 + e2) = {a + b for (a, b) in R(e1) × R(e2)}, where + denotes concatenation, and × denotes the cartesian product.
    Given an expression representing a set of words under the given grammar, return the sorted list of words that the expression represents.

    Example :
    Input: expression = "{a,b}{c,{d,e}}"
    Output: ["ac","ad","ae","bc","bd","be"]
 */



class Solution {
public:
    set<string> build(const string& s) {
        set<string> parts;
        set<string> curr = {""};

        int i = 0;

        while (i < s.size()) {
            if (s[i] == '{') {
                int j = i;
                int depth = 0;

                while (true) {
                    if (s[j] == '{') {
                        depth--;
                    } else if (s[j] == '}') {
                        depth++;
                    }

                    if (depth == 0) {
                        break;
                    }

                    j++;
                }

                set<string> options = build(
                    s.substr(i + 1, j - i - 1)
                );

                set<string> next;

                for (const string& a : curr) {
                    for (const string& b : options) {
                        next.insert(a + b);
                    }
                }

                curr = next;
                i = j + 1;
            }

            else if (s[i] == ',') {
                parts.insert(curr.begin(), curr.end());
                curr = {""};
                i++;
            }

            else {
                set<string> next;

                for (const string& x : curr) {
                    next.insert(x + s[i]);
                }

                curr = next;
                i++;
            }
        }

        parts.insert(curr.begin(), curr.end());

        return parts;
    }

    vector<string> braceExpansionII(string expression) {
        set<string> result = build(expression);

        return vector<string>(result.begin(), result.end());
    }
};