// Memoization
class Solution {
    int MOD = 1e9 + 7;
private:
    int solve(int day, int delay, int forget, vector<int> &dp){
        if(day == 1) return 1;
        if(dp[day] != -1) return dp[day];
        int result = 0;
        for(int prev = day - forget + 1; prev <= day - delay; prev++){
            if(prev > 0) result = (result + solve(prev, delay, forget, dp)) % MOD;
        }
        return dp[day] = result;
    }
public:
    int peopleAwareOfSecret(int n , int delay, int forget) {
        int total = 0;
        vector<int> dp(n+1, -1);
        for(int day = n - forget +1; day <= n; day++){
            if(day > 0) total = (total + solve(day, delay, forget, dp)) % MOD;
        }
        return total;
    }
};
