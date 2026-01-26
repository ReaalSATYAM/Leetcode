
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
