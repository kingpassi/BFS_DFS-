/******************************************************************************
542. 01 Matrix

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

Example 1:
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Example 2:
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
*******************************************************************************/
class Solution {
private:
    map<pair<int,int>,int> vis;
    map<pair<int,int>,int> lev;
    vector <pair<int, int>> movements;
public:
    Solution() {
        movements = {
        {0,1}, {0,-1}, {1,0}, {-1,0},
        };
    }

    bool isValid(int i, int j, int n, int m) {
        return i>=0 && j>=0 && i<n && j<m;
    }
    void mutisource_bfs(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]==0) {
                    q.push({i,j});
                    lev[{i,j}]=0;
                    vis[{i,j}]=1;
                }
            }
        }
        while(!q.empty()) {
            auto v = q.front();
            int v_x= v.first;
            int v_y=v.second;
            q.pop();

            for(auto movement : movements) {
                int child_x = movement.first+v_x;
                int child_y = movement.second+v_y;
                if(!isValid(child_x,child_y, n, m)) continue;
                if(vis[{child_x,child_y}]) continue;
                q.push({child_x,child_y});
                lev[{child_x,child_y}] = lev[{v_x,v_y}]+1;
                vis[{child_x,child_y}] = 1;
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        mutisource_bfs(mat);
        int n = mat.size();
        int m = mat[0].size();
        vector <int> index;
        vector<vector<int>> ans;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                index.push_back(lev[{i,j}]);
            }
            ans.push_back(index);
            index.clear();
        }
        return ans;
    }
};