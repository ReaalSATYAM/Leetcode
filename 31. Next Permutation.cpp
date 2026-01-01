// Using C++ in-built library
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};

// Optimal solution
/*
Algorithm Steps :
1. Find the first index ind from the right such that nums[ind] < nums[ind+1].
   This marks the pivot point where the next permutation is possible.
2. If no such index is found, the array is in descending order → reverse the whole array and return immediately.
3. Find the smallest number greater than nums[ind] to the right of ind, and swap them.
4. Reverse the subarray after index ind to get the next permutation.
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                ind = i;
                break;
            }
        }
        if(ind == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i = n-1; i > ind; i--){
            if(nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }
        reverse(nums.begin()+ ind + 1, nums.end());
        
    }
};
