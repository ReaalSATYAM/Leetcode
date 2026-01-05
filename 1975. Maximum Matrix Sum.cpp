/*
You are given an n x n integer matrix. You can do the following operation any number of times:
Choose any two adjacent elements of matrix and multiply each of them by -1.
Two elements are considered adjacent if and only if they share a border.
Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.
*/

/* Intution 
1. If the matrix has even no. of -ve elements, then simply take the absolute sum of the entire matrix.
2. In case of odd no. of -ve elements, there will always be one negative element left which can not be converted to +ve. So find the smallest negative element.  
*/
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
