// Brute force approach 
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int del_count = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int flag = 0;
            for(int j = 0; j< numsDivide.size(); j++){
                if(numsDivide[j] % nums[i] != 0){
                    flag = 1;
                    break;
                }
            }

            if(flag){
                int temp = nums[i]; 
                del_count++;
            }
            else return del_count;
        }
        return -1;
    }
};

// optimal solution using GCD
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g = numsDivide[0];
        for(int i = 1; i < numsDivide.size(); i++){
            g = __gcd(g, numsDivide[i]);
        }
        sort(nums.begin(), nums.end());
        int c = 0;
        for(auto it: nums){
            if(g % it == 0) return c;
            c++;
        }
        return -1;
    }
};
