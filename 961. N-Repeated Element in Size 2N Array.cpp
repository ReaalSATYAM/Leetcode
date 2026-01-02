// Brute force approach
class Solution {
public:
    int repeatedNTimes(vector<int>& nums){
        unordered_map<int, int> map;
        int key = nums.size()/2;
        for(int i = 0; i < nums.size(); i++){
            map.insert({nums[i], 0});
        }
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
        }
        for(int i = 0; i < nums.size(); i++){
            if(map[nums[i]] == key){
                return nums[i];
            }
        }
        return 0;
    }
};

class Solution {
public:
    int repeatedNTimes(vector<int>& nums){
        unordered_set<int> seen;
        for(int i = 0; i < nums.size(); i++){
            if(seen.count(nums[i])){
                return nums[i];
            }
            seen.insert(nums[i]);
        }
        return 0;
    }
};
