class Solution {
private:
    double triangleArea(vector<int>& A, vector<int>& B, vector<int>& C) {
        return 0.5 * abs( A[0] * (B[1] - C[1]) + B[0] * (C[1] - A[1]) + C[0] * (A[1] - B[1]));
    }
    
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double area = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    area = max(area, triangleArea(points[i], points[j], points[k]));
                }
            }
        }
        return area;
    }
};
