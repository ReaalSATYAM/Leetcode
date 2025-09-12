// Alice will win if there are odd no. of vowels
// Bob will win if there are even no. of vowels
class Solution {
private: 
    bool isVowel(char c){
        c = tolower(c);
        if(c == 'a' || c == 'e'||c == 'i' || c == 'o'|| c == 'u') return true;
        return false;
    }
public:
    bool doesAliceWin(string s) {
        int vowel = 0;
        for(char &c: s){
            if(isVowel(c)) vowel++;
        }
        if(vowel == 0) return false;
        return vowel > 0;
    }
};
