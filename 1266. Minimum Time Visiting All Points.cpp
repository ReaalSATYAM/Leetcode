class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int total_time = 0;
        for (int i = 1; i < points.size(); ++i) {
            int h_dis = abs(points[i][0] - points[i - 1][0]);
            int v_dis = abs(points[i][1] - points[i - 1][1]);
            total_time += max(
                h_dis, v_dis);
        }
        return total_time;
    }
};
