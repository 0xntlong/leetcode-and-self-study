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


class Fancy {
private:
    const int mod = 1e9 + 7;
    vector<long long> val;
    long long a, b;
    long long modPow(long long x, long long y, long long mod) {
        long long res = 1;
        x = x % mod;
        while (y > 0) {
            if (y % 2 == 1) {
                res = (res * x) % mod;
            }
            y = y / 2;
            x = (x * x) % mod;
        }
        return res;
    }
public:
    Fancy() : a(1), b(0) {
    }
    
    void append(int val) {
        long long x = (val - b + mod) % mod;
        this->val.push_back((x * modPow(a, mod - 2, mod)) % mod);
    }
    
    void addAll(int inc) {
        b = (b + inc) % mod;
    }
    
    void multAll(int m) {
        a = (a * m) % mod;
        b = (b * m) % mod;
    }
    
    int getIndex(int idx) {
        if (idx >= val.size()) 
            return -1;
        return (a * val[idx] + b) % mod;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */