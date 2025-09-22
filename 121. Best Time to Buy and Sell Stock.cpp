class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        int minIndValue = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
            minIndValue = min(minIndValue, prices[i]);
            sum = max(sum, prices[i] - minIndValue);
        }
        return sum;
    }
};
