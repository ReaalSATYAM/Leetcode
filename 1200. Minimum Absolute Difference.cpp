/*
Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.
Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows
a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr
*/
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        int minDiff = 1e8;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n - 1; i++){
            if(arr[i+1] - arr[i] < minDiff) minDiff = arr[i+1] - arr[i];
        }
        for(int i = 0; i < n - 1; i++){
            if(arr[i+1] - arr[i] == minDiff) 
                ans.push_back({arr[i], arr[i+1]});
        }
        return ans;
    }
};
