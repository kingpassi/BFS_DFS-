/******************************************************************************
547. Number of Provinces
There are n cities. Some of them are connected, while some are not.
If city a is connected directly with city b, and city b is connected directly
with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other 
cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 
if the ith city and the jth city are directly connected, and 
isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

Example 1:
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Example 2:
Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
*******************************************************************************/
class Solution {
    
    void dfs(vector<vector<int>>& isConnected, int i,int j){
        isConnected[i][j]=0;
        for(int k=0;k<isConnected.size();k++){
            if(isConnected[j][k]==1){
                dfs(isConnected,j,k);
            }
        }
    }
    
    
    
    
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1){
                    count+=1;
                    dfs(isConnected,i,j);
                }
                
            }
        }
    
        return count;
    }
};