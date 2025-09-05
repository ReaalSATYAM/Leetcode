class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(long long k = 1; k <= 60; k++){
            long long x = (long long)num1 - k * num2;
            if(x < 0) break;
            if(__builtin_popcountll(x) <= k && k <= x){
                return (int)k;
            }
        }
        return -1;
    }
};
