// Using array
class Solution {
public:
    int maxFreqSum(string s) {
        int hash[26] = {0};
        // finding frequency of each char in s.
        for(int i = 0; i < s.length(); i++){
            hash[s[i] - 'a']++;
        }
        int maxV = 0, maxC = 0;

        // finding the max frequency of vowels and consonants 
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'a' || s[i] == 'e'||s[i] == 'i' || s[i] == 'o'|| s[i] == 'u'){
                maxV = hash[s[i] - 'a'] > maxV? hash[s[i] - 'a']: maxV;
            }
            else maxC = hash[s[i] - 'a'] > maxC? hash[s[i] - 'a']: maxC;
        }
        return maxV + maxC;

    }
};
// Using hashmap
