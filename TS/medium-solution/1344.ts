/**
1344. Angle Between Hands of a Clock
    Given two numbers, hour and minutes, return the smaller angle (in degrees) formed between the hour and the minute hand.
    Answers within 10-5 of the actual value will be accepted as correct.

    Example :
    Input: hour = 12, minutes = 30
    Output: 165
 */



function angleClock(hour: number, minutes: number): number {
    const diff = Math.abs(hour * 30.0 - minutes * 5.5);

    return Math.min(diff, 360.0 - diff);
};