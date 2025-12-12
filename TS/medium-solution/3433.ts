/**
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
 */



function countMentions(numberOfUsers: number, events: string[][]): number[] {
    const [dp, onl] = [new Array(numberOfUsers).fill(0), Array.from({length: numberOfUsers}, () => [0, 0])];

    events.sort((a, b) => {
        return +a[1] === +b[1] ? a[0] === "OFFLINE" ? -1 : 1 : +a[1] - +b[1];
    });

    for (const [msg, timeStr, ppl] of events) {
        const t = +timeStr;
    
        for (let i = 0; i < numberOfUsers; i++) 
            if (onl[i][0] && onl[i][1] + 60 <= t) 
                onl[i][0] = onl[i][1] = 0;

        if (msg === "OFFLINE") {
            onl[+ppl][0] = 1;
            onl[+ppl][1] = t;
        } else {
            if (ppl === "ALL") 
                for (let i = 0; i < numberOfUsers; i++) 
                    dp[i] += 1;

            if (ppl === "HERE") 
                for (let i = 0; i < numberOfUsers; i++) 
                    if (!onl[i][0]) 
                        dp[i] += 1;

            if (ppl[0] === "i") 
                for (const id of ppl.split(' ').map(el => +el.slice(2))) 
                    dp[id] += 1;
        }
    }

    return dp;
};