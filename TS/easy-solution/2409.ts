/*
2409. Count Days Spent Together
    Alice and Bob are traveling to Rome for separate business meetings.
    You are given 4 strings arriveAlice, leaveAlice, arriveBob, and leaveBob. Alice will be in the city from the dates arriveAlice to leaveAlice (inclusive), while Bob will be in the city from the dates arriveBob to leaveBob (inclusive). Each will be a 5-character string in the format "MM-DD", corresponding to the month and day of the date.
    Return the total number of days that Alice and Bob are in Rome together.
    You can assume that all dates occur in the same calendar year, which is not a leap year. Note that the number of days per month can be represented as: [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31].

    Example :
    Input: arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", leaveBob = "08-19"
    Output: 3
    Explanation: Alice will be in Rome from August 15 to August 18. Bob will be in Rome from August 16 to August 19. They are both in Rome together on August 16th, 17th, and 18th, so the answer is 3.
*/



function countDaysTogether(arriveAlice: string, leaveAlice: string, arriveBob: string, leaveBob: string): number {
    const days: number[] = [
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    ];

    const convert = (date: string): number => {
        const [m, d] = date.split("-").map(Number);

        let total: number = d;

        for (let i = 0; i < m - 1; i++) {
            total += days[i];
        }

        return total;
    };

    const start: number = Math.max(
        convert(arriveAlice),
        convert(arriveBob)
    );

    const end: number = Math.min(
        convert(leaveAlice),
        convert(leaveBob)
    );

    return Math.max(0, end - start + 1);
};