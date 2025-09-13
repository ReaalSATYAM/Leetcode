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
// Using unordered map
class Solution {
public:
    int maxFreqSum(string s) {
        int count_v=0;
        int count_c=0;
        unordered_map<char,int>mp;
         for(int i=0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                mp[s[i]]++;
                count_v=max(count_v,mp[s[i]]);
            }
            else{
            mp[s[i]]++;
                count_c=max(count_c,mp[s[i]]);
            }
        }
        return count_v+count_c;
    }
};
