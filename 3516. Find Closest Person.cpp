class Solution {
public:
    int findClosest(int x, int y, int z) {
        // int x_dis = abs(z-x);
        // int y_dis = abs(z-y);
        if(abs(z-x) < abs(z-y)) return 1;
        else if(abs(z-y) < abs(z-x)) return 2;
        else return 0;
    }
};
