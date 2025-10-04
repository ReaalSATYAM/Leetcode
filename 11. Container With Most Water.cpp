class Solution {
public:
    int maxArea(vector<int>& height){
        int i = 0, j = height.size() - 1, v = 0, t;
        while(i<=j){
            if(height[i] >= height[j]){
                t = height[j] * (j-i);
                j--;
            }
            else{
                t = height[i] * (j-i);
                i++;
            }
            v = (t > v)? t: v;
        }
        return v;
    }
};
