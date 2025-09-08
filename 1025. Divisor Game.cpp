/*
    IMPORTANT
- Alice will win if n is even.
- If n is odd alice will loss.
*/
class Solution {
public:
    bool divisorGame(int n) {
        return n % 2 == 0;
    }
};
