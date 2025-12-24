/**
3074. Apple Redistribution into Boxes
    You are given an array apple of size n and an array capacity of size m.
    There are n packs where the ith pack contains apple[i] apples. There are m boxes as well, and the ith box has a capacity of capacity[i] apples.
    Return the minimum number of boxes you need to select to redistribute these n packs of apples into boxes.
    Note that, apples from the same pack can be distributed into different boxes.
    
    Example :
    Input: apple = [1,3,2], capacity = [4,3,1,5,2]
    Output: 2
    Explanation: We will use boxes with capacities 4 and 5.
    It is possible to distribute the apples as the total capacity is greater than or equal to the total number of apples.
 */




function minimumBoxes(apple: number[], capacity: number[]): number {
    let totalApple = apple.reduce((a, b) => a + b, 0);
    capacity.sort((a, b) => b - a);
    let capacities = 0;
    let cnt = 0;
    for (let cap of capacity){
        capacities += cap;
        cnt++;
        if (capacities >= totalApple)
            return cnt;
    }
    return cnt;
};