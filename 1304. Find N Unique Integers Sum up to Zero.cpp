// My own method
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        for(int i = n/2; i >= -1* (n/2); i--){
            if(n%2 == 0)
                if(i == 0) continue;
            ans.push_back(i);
        }
        return ans;
    }
};

// Standard method
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);
        for(int i = 0; i < n/2; i++){
            ans[2*i] = i + 1;
            ans[2*i+1] = -i -1;
        }
        return ans;
    }
};
