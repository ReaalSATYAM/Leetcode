class Solution {
public:
    int maxFreqSum(string s) {
        int hash[26] = {0};
        for(int i = 0; i < s.length(); i++){
            hash[s[i] - 'a']++;
        }
        int maxV = 0, maxC = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'a' || s[i] == 'e'||s[i] == 'i' || s[i] == 'o'|| s[i] == 'u'){
                maxV = hash[s[i] - 'a'] > maxV? hash[s[i] - 'a']: maxV;
            }
            else maxC = hash[s[i] - 'a'] > maxC? hash[s[i] - 'a']: maxC;
        }
        return maxV + maxC;

    }
};
