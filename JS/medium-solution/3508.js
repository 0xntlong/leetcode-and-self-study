/**
3508. Implement Router
    Design a data structure that can efficiently manage data packets in a network router. Each data packet consists of the following attributes:
    source: A unique identifier for the machine that generated the packet.
    destination: A unique identifier for the target machine.
    timestamp: The time at which the packet arrived at the router.
    Implement the Router class:
    Router(int memoryLimit): Initializes the Router object with a fixed memory limit.
    memoryLimit is the maximum number of packets the router can store at any given time.
    If adding a new packet would exceed this limit, the oldest packet must be removed to free up space.
    bool addPacket(int source, int destination, int timestamp): Adds a packet with the given attributes to the router.
    A packet is considered a duplicate if another packet with the same source, destination, and timestamp already exists in the router.
    Return true if the packet is successfully added (i.e., it is not a duplicate); otherwise return false.
    int[] forwardPacket(): Forwards the next packet in FIFO (First In First Out) order.
    Remove the packet from storage.
    Return the packet as an array [source, destination, timestamp].
    If there are no packets to forward, return an empty array.
    int getCount(int destination, int startTime, int endTime):
    Returns the number of packets currently stored in the router (i.e., not yet forwarded) that have the specified destination and have timestamps in the inclusive range [startTime, endTime].
    Note that queries for addPacket will be made in increasing order of timestamp.

    Example :
    Input:
    ["Router", "addPacket", "addPacket", "addPacket", "addPacket", "addPacket", "forwardPacket", "addPacket", "getCount"]
    [[3], [1, 4, 90], [2, 5, 90], [1, 4, 90], [3, 5, 95], [4, 5, 105], [], [5, 2, 110], [5, 100, 110]]
    Output:
    [null, true, true, false, true, true, [2, 5, 90], true, 1]
    Explanation
    Router router = new Router(3); // Initialize Router with memoryLimit of 3.
    router.addPacket(1, 4, 90); // Packet is added. Return True.
    router.addPacket(2, 5, 90); // Packet is added. Return True.
    router.addPacket(1, 4, 90); // This is a duplicate packet. Return False.
    router.addPacket(3, 5, 95); // Packet is added. Return True
    router.addPacket(4, 5, 105); // Packet is added, [1, 4, 90] is removed as number of packets exceeds memoryLimit. Return True.
    router.forwardPacket(); // Return [2, 5, 90] and remove it from router.
    router.addPacket(5, 2, 110); // Packet is added. Return True.
    router.getCount(5, 100, 110); // The only packet with destination 5 and timestamp in the inclusive range [100, 110] is [4, 5, 105]. Return 1.
 */




/**
 * @param {number} memoryLimit
 */
var Router = function(memoryLimit) {
    this.size = memoryLimit;
    this.packets = new Map();
    this.cnt = new Map();
    this.queue = [];
    this.head = 0;
};
Router.prototype._encode = function(source, destination, timestamp){
    return (BigInt(source) << 40n) | (BigInt(destination) << 20n) | BigInt(timestamp);
};
    Router.prototype._lb = function(a, x) { 
    let l = 0, r = a.length;
    while (l < r) {
        const m = (l + r) >> 1;
        if (a[m] >= x) r = m; else l = m + 1;
    }
    return l;
    };

    Router.prototype._ub = function(a, x) { 
    let l = 0, r = a.length;
    while (l < r) {
        const m = (l + r) >> 1;
        if (a[m] > x) r = m; else l = m + 1;
    }
    return l;
    };
/** 
 * @param {number} source 
 * @param {number} destination 
 * @param {number} timestamp
 * @return {boolean}
 */
Router.prototype.addPacket = function(source, destination, timestamp) {
    const key = this._encode(source, destination, timestamp);
    if (this.packets.has(key)) 
        return false;
    if (this.packets.size >= this.size) {
        this.forwardPacket();
    }

    this.packets.set(key, [source, destination, timestamp]);
    this.queue.push(key);
    const v = this.cnt.get(destination) || [];
    const pos = this._lb(v, timestamp);
    v.splice(pos, 0, timestamp); 
    this.cnt.set(destination, v);
    return true;
};

/**
 * @return {number[]}
 */
Router.prototype.forwardPacket = function() {
    if (this.packets.size === 0) 
        return [];
    if (this.head >= this.queue.length) 
        return [];
    const key = this.queue[this.head++];
    const packet = this.packets.get(key);
    if (!packet) 
        return [];
    this.packets.delete(key);
    const dest = packet[1], ts = packet[2];
    const v = this.cnt.get(dest);
    if (v && v.length) {
        const pos = this._lb(v, ts);
        if (pos < v.length && v[pos] === ts) v.splice(pos, 1);
    }
    if (this.head > 1024 && this.head * 2 > this.queue.length) {
        this.queue = this.queue.slice(this.head);
        this.head = 0;
    }
    return packet;
};

/** 
 * @param {number} destination 
 * @param {number} startTime 
 * @param {number} endTime
 * @return {number}
 */
Router.prototype.getCount = function(destination, startTime, endTime) {
    const v = this.cnt.get(destination) || [];
    if (v.length === 0) 
        return 0;
    const L = this._lb(v, startTime);
    const R = this._ub(v, endTime);
    return R - L;
    };

/** 
 * Your Router object will be instantiated and called as such:
 * var obj = new Router(memoryLimit)
 * var param_1 = obj.addPacket(source,destination,timestamp)
 * var param_2 = obj.forwardPacket()
 * var param_3 = obj.getCount(destination,startTime,endTime)
 */