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

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long n =  grid.size();
        n = n*n;
        long long sn = (n *(n+1))/2;
        long long s2n = (n*(n+1) * (2*n+1))/6;
        long s = 0, s2 = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                s += grid[i][j];
                s2 += (long)grid[i][j] * (long)grid[i][j];
            }
        }
        long long val1 = s - sn;
        long long val2 = s2 - s2n;
        val2 = val2/val1;
        long long x = (val1 + val2)/2;
        long long y = (val2 - x);
        return {(int)x, (int)y};
    }
};
