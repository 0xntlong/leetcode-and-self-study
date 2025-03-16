/**
2594. Minimum Time to Repair Cars
    You are given an integer array ranks representing the ranks of some mechanics. ranksi is the rank of the ith mechanic. A mechanic with a rank r can repair n cars in r * n2 minutes.
    You are also given an integer cars representing the total number of cars waiting in the garage to be repaired.
    Return the minimum time taken to repair all the cars.
    Note: All the mechanics can repair the cars simultaneously.
    Example :
    Input: ranks = [4,2,3,1], cars = 10
    Output: 16
    Explanation: 
    - The first mechanic will repair two cars. The time required is 4 * 2 * 2 = 16 minutes.
    - The second mechanic will repair two cars. The time required is 2 * 2 * 2 = 8 minutes.
    - The third mechanic will repair two cars. The time required is 3 * 2 * 2 = 12 minutes.
    - The fourth mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
    It can be proved that the cars cannot be repaired in less than 16 minutes.
 */

    function repairCars(ranks: number[], cars: number): number {
        let left : number = 1, right : number = Math.max(...ranks) * cars * cars;
        function canFixInTime(T : number) : boolean{
            let total_cars : number = ranks.reduce((sum, r) => sum + Math.floor(Math.sqrt(T / r)), 0);
            return total_cars >= cars;
        }
        while (left < right){
            let mid : number = Math.floor((left + right) / 2);
            if (canFixInTime(mid)){
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    };