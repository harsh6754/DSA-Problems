#include<bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     int minimumCostPath(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         int dp[m+1][n+1];
//         for(int i=0;i<=n;i++)
//         {
//             dp[0][i]=0;
//         }
//         for(int i=0;i<=m;i++)
//         {
//             dp[i][0]=0;
//         }
//         for(int i=1;i<=n;i++){
//           dp[1][i]=grid[0][i-1]+dp[1][i-1];
//       }
//       for(int j=1;j<=m;j++){
//           dp[j][1]=grid[j-1][0]+dp[j-1][1];
//       }
//         for(int i=2;i<=m;i++)
//         {
//             for(int j=2;j<=n;j++)
//             {
//                 dp[i][j]=grid[i-1][j-1]+min(dp[i][j-1],dp[i-1][j]); 
//             }
//         }
//         return dp[m][n];
//     }
// };

class Solution
{
    public:
    
    #define p pair<int,pair<int,int>>
    int minimumCostPath(vector<vector<int>>& grid)
    {
        int n=grid.size(),m=grid[0].size();
        priority_queue<p,vector<p>,greater<p>>pq;
                
        vector<vector<int>>dij(n,vector<int>(m,1e9));
        dij[0][0]=0;
        pq.push({grid[0][0],{0,0}});
        int drow[]={1,-1,0,0};
        int dcol[]={0,0,1,-1};
        while(!pq.empty())
        {
          auto it=pq.top();
          int dist=it.first;
          int row=it.second.first;
          int col=it.second.second;
          pq.pop();
          if(row==n-1 && col==m-1)return dij[n-1][m-1];
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m )
                {
                    if(dist+grid[nrow][ncol]<dij[nrow][ncol])
                    {
                        dij[nrow][ncol]=dist+grid[nrow][ncol];
                        pq.push({dij[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};


int main(){
    int rows;
    int cols;
    cin>>rows>>cols;

    vector<vector<int>>grid(rows,vector<int>(cols));
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            cin>>grid[i][j];
        }
    }

   Solution solution;
   int result = solution.minimumCostPath(grid);
   cout<<result;

    return 0;
}