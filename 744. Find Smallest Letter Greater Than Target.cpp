class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        if(target >= letters[n-1]) return letters[0];
        int l = 0, r = n-1, m;
        while(l <= r){
            m = l+(r-l)/2;;
            if(letters[m] <= target) l = m+1;
            else r = m-1;
        }
        return letters[l];
    }
};
