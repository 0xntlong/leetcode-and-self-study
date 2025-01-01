"""
2325. Decode the Message
    You are given the strings key and message, which represent a cipher key and a secret message, respectively. The steps to decode message are as follows:
    Use the first appearance of all 26 lowercase English letters in key as the order of the substitution table.
    Align the substitution table with the regular English alphabet.
    Each letter in message is then substituted using the table.
    Spaces ' ' are transformed to themselves.
    For example, given key = "happy boy" (actual key would have at least one instance of each letter in the alphabet), we have the partial substitution table of ('h' -> 'a', 'a' -> 'b', 'p' -> 'c', 'y' -> 'd', 'b' -> 'e', 'o' -> 'f').
    Return the decoded message.

    Example :
    Input: key = "the quick brown fox jumps over the lazy dog", message = "vkbs bs t suepuv"
    Output: "this is a secret"
    Explanation: The diagram above shows the substitution table.
    It is obtained by taking the first appearance of each letter in "the quick brown fox jumps over the lazy dog".
"""


class Solution:
    def decodeMessage(self, key: str, message: str) -> str:
        alphabet={}
        k = 0
        for c in key:
            if c != ' ' and c not in alphabet:
                alphabet[c] = chr(k + ord('a'))
                k += 1
        decode = []
        for c in message:
            if c != ' ':
                decode.append(alphabet[c])
            else:
                decode.append(' ')
        return ''.join(decode)
            