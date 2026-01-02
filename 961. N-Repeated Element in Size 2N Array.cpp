/*
You are given an integer array nums with the following properties:
nums.length == 2 * n.
nums contains n + 1 unique elements.
Exactly one element of nums is repeated n times.
Return the element that is repeated n times.
*/

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

// Optimal approach
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
