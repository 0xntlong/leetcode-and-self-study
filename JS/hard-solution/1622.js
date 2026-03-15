/**
1622. Fancy Sequence
    Write an API that generates fancy sequences using the append, addAll, and multAll operations.
    Implement the Fancy class:
    Fancy() Initializes the object with an empty sequence.
    void append(val) Appends an integer val to the end of the sequence.
    void addAll(inc) Increments all existing values in the sequence by an integer inc.
    void multAll(m) Multiplies all existing values in the sequence by an integer m.
    int getIndex(idx) Gets the current value at index idx (0-indexed) of the sequence modulo 109 + 7. If the index is greater or equal than the length of the sequence, return -1.

    Example :
    Input
    ["Fancy", "append", "addAll", "append", "multAll", "getIndex", "addAll", "append", "multAll", "getIndex", "getIndex", "getIndex"]
    [[], [2], [3], [7], [2], [0], [3], [10], [2], [0], [1], [2]]
    Output
    [null, null, null, null, null, 10, null, null, null, 26, 34, 20]
    Explanation
    Fancy fancy = new Fancy();
    fancy.append(2);   // fancy sequence: [2]
    fancy.addAll(3);   // fancy sequence: [2+3] -> [5]
    fancy.append(7);   // fancy sequence: [5, 7]
    fancy.multAll(2);  // fancy sequence: [5*2, 7*2] -> [10, 14]
    fancy.getIndex(0); // return 10
    fancy.addAll(3);   // fancy sequence: [10+3, 14+3] -> [13, 17]
    fancy.append(10);  // fancy sequence: [13, 17, 10]
    fancy.multAll(2);  // fancy sequence: [13*2, 17*2, 10*2] -> [26, 34, 20]
    fancy.getIndex(0); // return 26
    fancy.getIndex(1); // return 34
    fancy.getIndex(2); // return 20

 */



/**
 * @description Fancy sequence implementation using BigInt for precision
 * and modular inverse for O(1) updates.
 */
var Fancy = function() {
    this.mod = BigInt(10**9 + 7);
    this.values = [];
    this.a = 1n; 
    this.b = 0n; 
};

/** * Helper: Modular Exponentiation (Fast Power)
 * Computes (base^exp) % mod
 */
Fancy.prototype.power = function(base, exp) {
    let res = 1n;
    base %= this.mod;
    while (exp > 0n) {
        if (exp % 2n === 1n) res = (res * base) % this.mod;
        base = (base * base) % this.mod;
        exp /= 2n;
    }
    return res;
};

/** * Helper: Modular Inverse using Fermat's Little Theorem
 * Since mod is prime, a^(mod-2) % mod is the inverse.
 */
Fancy.prototype.modInverse = function(n) {
    return this.power(n, this.mod - 2n);
};

/** * @param {number} val
 * @return {void}
 */
Fancy.prototype.append = function(val) {
    let valBI = BigInt(val);
    let invA = this.modInverse(this.a);
    let x = ((valBI - this.b + this.mod) % this.mod * invA) % this.mod;
    this.values.push(x);
};

/** * @param {number} inc
 * @return {void}
 */
Fancy.prototype.addAll = function(inc) {
    this.b = (this.b + BigInt(inc)) % this.mod;
};

/** * @param {number} m
 * @return {void}
 */
Fancy.prototype.multAll = function(m) {
    let mBI = BigInt(m);
    this.a = (this.a * mBI) % this.mod;
    this.b = (this.b * mBI) % this.mod;
};

/** * @param {number} idx
 * @return {number}
 */
Fancy.prototype.getIndex = function(idx) {
    if (idx >= this.values.length) 
        return -1;
    let result = (this.a * this.values[idx] + this.b) % this.mod;
    return Number(result);
};