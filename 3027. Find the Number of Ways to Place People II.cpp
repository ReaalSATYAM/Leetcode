class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        auto cmp = [&](vector<int> &c, vector<int> &t){
            // First, sort the points based on the x-coordinate, and then y-coordinate in descending order if x-coordinates are equal.
            if(c[0] == t[0]) return c[1] > t[1];
            return c[0] < t[0];
        };
        sort(points.begin(), points.end(), cmp);

        int ans = 0;
        for(int i = 0; i < n; i++){
            int cx = points[i][0], cy = points[i][1];
            long k = INT_MIN;
            for(int j = i + 1; j< n; j++){
                int tx = points[j][0], ty = points[j][1];
                // continue if ty is heigher than cy 
                if(ty > cy) continue;
                // Check if the y cordinate is within the threshold value
                if(ty > k){
                    ans++;
                    k = ty;
                }
            }
        }
        return ans;
    }
};
