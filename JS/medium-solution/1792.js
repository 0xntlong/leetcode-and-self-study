/*
1792. Maximum Average Pass Ratio
    There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.
    You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.
    The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.
    Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted.

    Example :
    Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
    Output: 0.78333
    Explanation: You can assign the two extra students to the first class. The average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.
*/



/**
 * @param {number[][]} classes
 * @param {number} extraStudents
 * @return {number}
 */
var maxAverageRatio = function(classes, extraStudents) {
     const n = classes.length
    const pq = new PriorityQueue((a, b) => b[0] - a[0])

    for (let i = 0; i < n; i++) {
        let [pass, total] = classes[i]
        let currentAverage = Number(pass / total)
        let newAverage = Number((pass + 1) / (total + 1))
        let gain = newAverage - currentAverage
        pq.enqueue([gain, i])
    }

    while (extraStudents--) {
        const [currentGain, currentClass] = pq.dequeue()

        classes[currentClass][0]++
        classes[currentClass][1]++

        const newAverage = Number(classes[currentClass][0] / classes[currentClass][1])
        const nextAverage = Number((classes[currentClass][0] + 1) / (classes[currentClass][1] + 1))

        let gain = nextAverage - newAverage
        pq.enqueue([gain, currentClass])

    }

    let result = 0

    for (let i = 0; i < n; i++) {
        result += Number(classes[i][0] / classes[i][1])
    }

    return result / n
};