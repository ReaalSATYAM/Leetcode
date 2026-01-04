// Naive approach(Will give TLE)
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int total = 0;
        for(int i = 0 ; i < nums.size(); i++){
            int c = 1, temp = 1;
            for(int j = 2; j <= nums[i]; j++){
                if(nums[i] % j == 0){
                    temp += j;
                    c++;
                }
            }  
            if(c == 4){
                total += temp;
            }
        }
        return total;
    }
};
