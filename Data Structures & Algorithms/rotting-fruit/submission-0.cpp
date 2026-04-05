class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh = 0;
        int time = 0;

        int m = grid.size();
        int n = grid[0].size();

        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                if(grid[r][c] == 1){
                    fresh++;
                }
                if(grid[r][c] == 2){
                    q.push({r, c});
                }
            }
        }

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while(fresh > 0 && !q.empty()){
            int length = q.size();
            for(int i = 0; i < length; i++){
                auto cur = q.front();
                q.pop();
                int r = cur.first;
                int c = cur.second;

                for(const auto& dir : directions){
                    int row = r + dir.first;
                    int col = c + dir.second;
                    if(row >= 0 && col >= 0 && row < m && c < n && grid[row][col] == 1){
                        grid[row][col]= 2;
                        q.push({row, col});
                        fresh--;
                    }
                }
            }
            time++;
        }
        return fresh == 0 ? time : -1;
    }
};
