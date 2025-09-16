// Time complexity: O(Nlogm)
// Space complexity: O(1) 

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res;// we can use a stack too but than we need to convert to a vector before returning. So it is better to use a vector as a stack.
        for(int i = 0; i < nums.size(); i++){
            while(!res.empty()){
                int prev = res.back();
                int curr = nums[i];
                int GCD = gcd(prev, curr);
                if(GCD == 1) break;

                res.pop_back();
                int LCM = prev/GCD * curr;
                nums[i] = LCM;
            }
            res.push_back(nums[i]);
            
        }
        return res;
    }
};
