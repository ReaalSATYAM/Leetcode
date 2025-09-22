class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freqTable;
        int MAX = INT_MIN;
        for(int it: nums){
            freqTable[it]++;
            if(freqTable[it] > MAX){
                MAX = freqTable[it];
            }
        }
        int count = 0;
        for(auto it: freqTable){
            if(it.second == MAX) {
                count += it.second;
            }
        }
        return count;
    }
};
