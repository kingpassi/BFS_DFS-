/******************************************************************************
994. Rotting Oranges

You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to 
a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell
has a fresh orange. If this is impossible, return -1.

Example 1:
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) 
is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
*******************************************************************************/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        if(!grid.size())
            return 0;
        
        int row = grid.size();
        int col = grid[0].size();
        
        int time = 0;
        int fresh = 0;
        queue<pair<int, int>> rotten;
        
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] == 1)
                    fresh++;
                else if(grid[i][j] == 2)
                    rotten.push({i, j});
            }   
        }
        
        vector<int> dx{0, 0, 1, -1};
        vector<int> dy{1, -1, 0, 0};
        
        while(!rotten.empty())
        {
            int size = rotten.size();
            
            for(int i = 0; i < size; i++)
            {
                int X = rotten.front().first;
                int Y = rotten.front().second;
                rotten.pop();
                
                for(int j = 0; j < dx.size(); j++)
                {
                    int x = X + dx[j];
                    int y = Y + dy[j];
                    
                    if(x < 0 || x >= row || y < 0 || y >= col || grid[x][y] != 1)
                        continue;
                    
                    grid[x][y]= 2;
                    rotten.push({x, y});
                    fresh--;
                }
            }
            
            if(!rotten.empty())
                time++; 
        }   
        
        if(!fresh)
            return time;
        else
            return -1;
    }
};