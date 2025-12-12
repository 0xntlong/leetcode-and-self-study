"""
3433. Count Mentions Per User
    You are given an integer numberOfUsers representing the total number of users and an array events of size n x 3.
    Each events[i] can be either of the following two types:
    Message Event: ["MESSAGE", "timestampi", "mentions_stringi"]
    This event indicates that a set of users was mentioned in a message at timestampi.
    The mentions_stringi string can contain one of the following tokens:
    id<number>: where <number> is an integer in range [0,numberOfUsers - 1]. There can be multiple ids separated by a single whitespace and may contain duplicates. This can mention even the offline users.
    ALL: mentions all users.
    HERE: mentions all online users.
    Offline Event: ["OFFLINE", "timestampi", "idi"]
    This event indicates that the user idi had become offline at timestampi for 60 time units. The user will automatically be online again at time timestampi + 60.
    Return an array mentions where mentions[i] represents the number of mentions the user with id i has across all MESSAGE events.
    All users are initially online, and if a user goes offline or comes back online, their status change is processed before handling any message event that occurs at the same timestamp.
    Note that a user can be mentioned multiple times in a single message event, and each mention should be counted separately.

    Example :
    Input: numberOfUsers = 2, events = [["MESSAGE","10","id1 id0"],["OFFLINE","11","0"],["MESSAGE","71","HERE"]]
    Output: [2,2]
    Explanation:
    Initially, all users are online.
    At timestamp 10, id1 and id0 are mentioned. mentions = [1,1]
    At timestamp 11, id0 goes offline.
    At timestamp 71, id0 comes back online and "HERE" is mentioned. mentions = [2,2]
"""



from typing import List

class Solution:
    def countMentions(self, numberOfUsers: int, events: List[List[str]]) -> List[int]:
        dp = [0] * numberOfUsers
        onl = [0] * numberOfUsers
        events.sort(key = lambda x : (int(x[1]), x[0] == "MESSAGE"))
        for msg, time, ppl in events:
            t = int(time)
            if msg == "MESSAGE":
                if ppl == "ALL":
                    for i in range(numberOfUsers):
                        dp[i] += 1
                elif ppl == "HERE":
                    for i in range(numberOfUsers):
                        if t >= onl[i]:
                            dp[i] += 1
                else:
                    for p in ppl.replace("id", "").split():
                        dp[int(p)] += 1
            else:
                onl[int(ppl)] = t + 60
        return dp