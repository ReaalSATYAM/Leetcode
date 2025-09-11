// Method 1
class Solution {
private:
    bool isChar(char c){
        c = tolower(c);
        if(c == 'a' || c == 'e'||c == 'i' || c == 'o'|| c == 'u') return true;
        return false;
    }

public:
    string sortVowels(string s) {
        vector<char> v;
        for(char &c: s){
            if(isChar(c)) v.push_back(c);
        } 
        sort(v.begin(), v.end(), [](char a, char b){
            return a < b;
        });

        int i = 0;
        for(char &c: s){
            if(isChar(c)){
                c = v[i++];
            }     
        }
        return s;
    }
};
