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



/**
 * @param {string} expression
 * @return {string[]}
 */
var braceExpansionII = function(expression) {
    const build = (s) => {
        const parts = new Set();
        let curr = new Set([""]);

        let i = 0;

        while (i < s.length) {
            if (s[i] === "{") {
                let j = i;
                let depth = 0;

                while (true) {
                    if (s[j] === "{") {
                        depth--;
                    } else if (s[j] === "}") {
                        depth++;
                    }

                    if (depth === 0) {
                        break;
                    }

                    j++;
                }

                const options = build(
                    s.substring(i + 1, j)
                );

                const next = new Set();

                for (const a of curr) {
                    for (const b of options) {
                        next.add(a + b);
                    }
                }

                curr = next;
                i = j + 1;
            }

            else if (s[i] === ",") {
                for (const x of curr) {
                    parts.add(x);
                }

                curr = new Set([""]);
                i++;
            }

            else {
                const next = new Set();

                for (const x of curr) {
                    next.add(x + s[i]);
                }

                curr = next;
                i++;
            }
        }

        for (const x of curr) {
            parts.add(x);
        }

        return parts;
    };

    return [...build(expression)].sort();
};