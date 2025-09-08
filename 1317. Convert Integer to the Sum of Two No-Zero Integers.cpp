class Solution {
private:
    // checks if the given number have zero or not
    bool no_zero(int n){
        while(n > 0){
            if(n % 10 == 0) return false;
            n /= 10;
        }
        return true;
    }
public:
    // we are checking all the possible values of of a and b (no zero decimal values only)
    vector<int> getNoZeroIntegers(int n) {
       for(int i = 1; i <= (n+1)/2; i++){
            int pos_a = i;
            int pos_b = n - i;
            if(no_zero(pos_a) && no_zero(pos_b)){
                return {pos_a, pos_b};
            }
       }
       return {0,0};
    }
};
