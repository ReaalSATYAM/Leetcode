class Router {
public:
    int MAX_SIZE;
    unordered_map<string, vector<int>> packetMap;
    unordered_map<int, vector<int>> timeDesMap;
    queue<string> que;

    Router(int memoryLimit) {
        MAX_SIZE = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        string packet = to_string(source) + "_" + to_string(destination) + "_" + to_string(timestamp);
        
        if(packetMap.find(packet) != packetMap.end()) {
            return false;
        }

        if(que.size() >= MAX_SIZE) {
            forwardPacket();
        }

        packetMap[packet] = {source, destination, timestamp};
        que.push(packet);
        timeDesMap[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (que.empty()) {
            return {};
        }
        
        string key = que.front();
        que.pop();
        vector<int> packet = packetMap[key];
        packetMap.erase(key);

        int d = packet[1];
        timeDesMap[d].erase(timeDesMap[d].begin());  // Remove the oldest timestamp for the destination
        return packet;
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = timeDesMap.find(destination);
        if (it == timeDesMap.end() || it->second.empty()) {
            return 0;
        }

        vector<int>& timeStamps = it->second;
        int l = lower_bound(timeStamps.begin(), timeStamps.end(), startTime) - timeStamps.begin();
        int r = upper_bound(timeStamps.begin(), timeStamps.end(), endTime) - timeStamps.begin();
        return r - l;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
