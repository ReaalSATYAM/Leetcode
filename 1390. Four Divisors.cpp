// Naive approach(Will give TLE)
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int total = 0;
        for(int i = 0 ; i < nums.size(); i++){
            int c = 1, temp = 1;
            // Finding all the divisors of the element
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

//Better approach
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int total = 0;
        for(int i = 0 ; i < nums.size(); i++){
            int c = 2, temp = 1, f = 0;
            // iterating till n/2
            for(int j = 2; j <= nums[i]/2; j++){
                if(nums[i] % j == 0){
                    temp += j;
                    c++;
                }
                // Break if c > 4
                if(c > 4){
                    f = 1;
                    break;
                }
            }  
            if(!f && c == 4){
                total += temp + nums[i];
            }
        }
        return total;
    }
};

// Best approach
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int total = 0;
        for(int i = 0 ; i < nums.size(); i++){
            int c = 2, temp = 1 + nums[i];
            // Running till sqrt(n)
            for(int j = 2; j <= sqrt(nums[i]); j++){
                if(nums[i] % j == 0){
                    temp += j;
                    c++;
                    // Count only onces in case of perfect square
                    if(j * j != nums[i]){
                        c++;
                        temp += nums[i]/j;
                    }
                }
            }  
            if(c == 4){
                total += temp;
            }
        }
        return total;
    }
};
