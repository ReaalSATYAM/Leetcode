class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
       int c = 0;
        for(int i = 0; i < arr.size(); i++){
            for(int j = i+1; j < arr.size(); j++){
                if(arr[i] + arr[j] <= 0) continue;
                if((arr[i] + arr[j]) % k == 0) c++;
            }
        }
        return (c >= arr.size()/2 ) ? true: false;
    }
};
