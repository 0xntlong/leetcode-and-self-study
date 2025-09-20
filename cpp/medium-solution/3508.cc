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

#include <bits/stdc++.h>
using namespace std;


class Router {
    using ll = long long;
    int size_;
    unordered_map<ll, array<int, 3>> packets;
    unordered_map<int, vector<int>> cnt;
    queue<ll> q;

    static ll encode(int s, int d, int t){
        return (((ll)s << 40) | ((ll)d << 20) | (ll)t); 
    }

public:
    Router(int memoryLimit) {
        size_ = memoryLimit;  
        packets.reserve(max(1, memoryLimit * 2));
    }
    bool addPacket(int source, int destination, int timestamp) {
        ll key = encode(source, destination, timestamp);
        if (packets.count(key))
            return false;
        if ((int)packets.size() >= size_){
            forwardPacket();
        }
        packets[key] = {source, destination, timestamp};
        q.push(key);
    
        auto &v = cnt[destination];
        auto it = lower_bound(v.begin(), v.end(), timestamp);
        v.insert(it, timestamp);
        return true;
    }
    vector<int> forwardPacket() {
        if (packets.empty())
            return {};
        ll key = q.front();
        q.pop(); 
        auto it = packets.find(key);
        if (it == packets.end())
            return {};
        auto packet = it->second;
        packets.erase(it);
        int d = packet[1];
        int ts = packet[2];
        auto &v = cnt[d];
        auto itv = lower_bound(v.begin(), v.end(), ts);
        if (itv != v.end() && *itv == ts) 
            v.erase(itv);
        return {packet[0], packet[1], packet[2]};
    }
    int getCount(int destination, int startTime, int endTime) {
        auto it = cnt.find(destination);
        if (it == cnt.end())
            return 0;
        auto &v = it->second;
        auto L = lower_bound(v.begin(), v.end(), startTime);
        auto R = upper_bound(v.begin(), v.end(), endTime);
        return (int)(R - L);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */