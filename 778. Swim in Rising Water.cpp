// Solution 1
class Solution {
private:
// Find with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  
        }
        return parent[x];
    }

public:
    vector<int> parent; 
  
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
      
        parent.resize(n * n);
        for (int i = 0; i < parent.size(); ++i) {
            parent[i] = i;
        }
        vector<int> heightToIndex(n * n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                heightToIndex[grid[i][j]] = i * n + j;
            }
        }
      
        vector<int> directions = {-1, 0, 1, 0, -1};
      
        for (int time = 0; time < n * n; ++time) {
            int currentIndex = heightToIndex[time];
            int row = currentIndex / n;
            int col = currentIndex % n;

            for (int k = 0; k < 4; ++k) {
                int newRow = row + directions[k];
                int newCol = col + directions[k + 1];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && 
                    grid[newRow][newCol] <= time) {
                    int adjacentIndex = newRow * n + newCol;
                    parent[find(adjacentIndex)] = find(currentIndex);
                }
                if (find(0) == find(n * n - 1)) {
                    return time;
                }
            }
        }
      
        return -1; 
    }
  
};

// Solution 2
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>visit(n, vector<int>(n,0));

        pq.push({grid[0][0],{0,0}});
        int ans = 0;
        vector<int>dirx{1,-1,0,0};
        vector<int>diry{0,0,1,-1};

        while(!pq.empty()){
            auto it = pq.top();
            int elevate = it.first;
            int xcor = it.second.first;
            int ycor = it.second.second;

            if(xcor==n-1 && ycor == n-1) return elevate;
            pq.pop();

            for(int i=0; i<4; i++){
                int newx = xcor + dirx[i];
                int newy = ycor + diry[i];

                if(newx<0 || newx>=n || newy<0 || newy>=n || visit[newx][newy])continue;
                visit[newx][newy] = 1;
                pq.push({max(elevate, grid[newx][newy]), {newx, newy}});
                

            }
        }
        return ans;
    }
};
