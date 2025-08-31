// Better solution
// Time & space complexity = O(n^2)
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n =  grid.size();
        vector<int> hash(n*n + 1, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < n; j++){
                hash[grid[i][j]]++;
            }
        }
        int dup = 0, mis = 0;
        for(int i = 1; i < n*n+1; i++){
            if(hash[i] == 2) dup = i;
            else if(hash[i] == 0) mis = i;
            if(dup > 0 && mis > 0) break;
        }
        return {dup, mis};
    }
};
