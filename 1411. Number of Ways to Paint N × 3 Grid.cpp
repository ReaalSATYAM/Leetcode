/*
You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colors: Red, Yellow, or Green while making sure that no two adjacent cells have the same color (i.e., no two cells that share vertical or horizontal sides have the same color).
Given n the number of rows of the grid, return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed modulo 109 + 7.
*/
class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;
        long long patternABA = 6;  
        long long patternABC = 6; 
        while(--n){
            long long nextPatternABA = (patternABA * 3 + patternABC * 2) % MOD;
            long long nextPatternABC = (patternABA * 2 + patternABC * 2) % MOD;
            patternABA = nextPatternABA;
            patternABC = nextPatternABC;
        }
        return (int)((patternABA + patternABC) % MOD);
    }
};
