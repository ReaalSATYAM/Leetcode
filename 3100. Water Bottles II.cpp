class Solution {
 public:
  int maxBottlesDrunk(int numBottles, int numExchange) {
    int ans = numBottles;

    while (numBottles >= numExchange) {
      numBottles = (numBottles - numExchange + 1);
      ++numExchange;
      ++ans;
    }

    return ans;
  }
};

// Or
class Solution {
public:
    int maxBottlesDrunk(int nB, int nE) {
        int x=nB;
        int y=nE;
        int h=(((-2*y)+3+sqrt(4*y*y+8*x-12*y+1))/2);
        return x+h;
    }
};
