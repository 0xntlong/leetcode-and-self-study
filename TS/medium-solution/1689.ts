/**
1689. Partitioning Into Minimum Number Of Deci-Binary Numbers
    A decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros. For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.
    Given a string n that represents a positive decimal integer, return the minimum number of positive deci-binary numbers needed so that they sum up to n.
    Example :

    Input: n = "32"
    Output: 3
    Explanation: 10 + 11 + 11 = 32
 */



function minPartitions(n: string): number {
    for (let d = 9; d >= 1; d--) {
        if (n.includes(d.toString()))
            return d;
    }
    return 0;
};