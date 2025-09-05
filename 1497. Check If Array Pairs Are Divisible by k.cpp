// Brute force approach
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

// optimal solution
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> map(k, 0); 
        
        for(auto a: arr){
            int rem = a%k;
            if(rem < 0) rem += k;
            map[rem]++;
        }
        if(map[0] % 2 != 0) return false; 
        for(int i = 1; i <= k/2; i++){
            if(map[i] != map[k-i]) return false;
        }
        return true;
    }
};
