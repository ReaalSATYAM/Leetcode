class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int c = 0, minE = INT_MAX;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] < 0){
                    c++;
                }
                ans += abs(matrix[i][j]);
                minE = min(minE, abs(matrix[i][j])); 
            }
        }
        if(c % 2 == 0){
            return ans;
        }
        else{
            return ans - 2*minE;
        }
        
    }
};
