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
