/**
1665. Minimum Initial Energy to Finish Tasks
    You are given an array tasks where tasks[i] = [actuali, minimumi]:
    actuali is the actual amount of energy you spend to finish the ith task.
    minimumi is the minimum amount of energy you require to begin the ith task.
    For example, if the task is [10, 12] and your current energy is 11, you cannot start this task. However, if your current energy is 13, you can complete this task, and your energy will be 3 after finishing it.
    You can finish the tasks in any order you like.
    Return the minimum initial amount of energy you will need to finish all the tasks.

    Example 1:
    Input: tasks = [[1,2],[2,4],[4,8]]
    Output: 8
    Explanation:
    Starting with 8 energy, we finish the tasks in the following order:
        - 3rd task. Now energy = 8 - 4 = 4.
        - 2nd task. Now energy = 4 - 2 = 2.
        - 1st task. Now energy = 2 - 1 = 1.
    Notice that even though we have leftover energy, starting with 7 energy does not work because we cannot do the 3rd task.

 */


/**
 * @param {number[][]} tasks
 * @return {number}
 */
var minimumEffort = function(tasks) {
    tasks.sort((a, b) => (b[1] - b[0]) - (a[1] - a[0]));
    let need = 0;
    for (let i = tasks.length - 1; i >= 0; i--) {
        const [actual, minimum] = tasks[i];
        need = Math.max(minimum, need + actual);
    }
    return need;
};