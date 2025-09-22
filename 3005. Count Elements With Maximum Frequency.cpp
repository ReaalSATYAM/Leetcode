class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freqTable;
        int MAX = INT_MIN;
        // filling frequency table. Also finding the max frequency.
        for(int it: nums){
            freqTable[it]++;
            if(freqTable[it] > MAX){
                MAX = freqTable[it];
            }
        }
        int count = 0;
        // iterating over the freqTable to find elements with maximum frequency 
        for(auto it: freqTable){
            if(it.second == MAX) {
                count += it.second;
            }
        }
        return count;
    }
};
