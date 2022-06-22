/******************************************************************************
695. Max Area of Island

You are given an m x n binary matrix grid. An island is a group of 1's
(representing land) connected 4-directionally (horizontal or vertical.) 
You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

Example 1:


Input: grid = 
[[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],
[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],
[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],
[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 
4-directionally.

Example 2:
Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
*******************************************************************************/
class Solution {
public:
    
    vector<int>vec;
    int dfs(vector<vector<int>>& grid,int i, int j, int n,int m ){
        if(i<0 ||j<0|| i>=n||j>=m|| grid[i][j]!=1) return 0;
        grid[i][j]=2;
        return (1+dfs(grid,i,j+1,n,m)+dfs(grid,i,j-1,n,m)+dfs(grid,i+1,j,n,m)+dfs(grid,i-1,j,n,m));
    } 
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int MaxArea=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    MaxArea=max(MaxArea,dfs(grid,i,j,n,m));
                }
            }
        }
        if(MaxArea==INT_MIN) return 0;
        
        return MaxArea;
    }
};