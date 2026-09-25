"""
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
"""


class Solution:
    def braceExpansionII(self, expression: str) -> list[str]:
        def build(s):
            parts = set()
            curr = {""}
            i = 0

            while i < len(s):
                if s[i] == '{':
                    j = i
                    depth = 0

                    while True:
                        if s[j] == '{':
                            depth -= 1
                        elif s[j] == '}':
                            depth += 1

                        if depth == 0:
                            break

                        j += 1

                    options = build(s[i + 1:j])
                    curr = {a + b for a in curr for b in options}
                    i = j + 1

                elif s[i] == ',':
                    parts |= curr
                    curr = {""}
                    i += 1

                else:
                    curr = {x + s[i] for x in curr}
                    i += 1

            parts |= curr
            return parts

        return sorted(build(expression))