class Solution {

public:
    int cost(int n,int m,vector<vector<int>>& grid,int r,int c1,int c2){
        if(r>=n || c1<0 || c2<0 ||c1>=m || c2>=m)
            return 0;
        if(c1==c2)
            return grid[r][c1];
        else
            return grid[r][c1]+grid[r][c2];
    }
    int find(int n,int m,vector<vector<int>>& grid,int dp[][70][70],int row,int col1,int col2){
        
        
        if(row>=n || col1>=m || col2>=m || col1<0 || col2<0)
            return 0;
        if(dp[row][col1][col2]!=-1)
            return dp[row][col1][col2];
        int ans = cost(n,m,grid,row,col1,col2);
        if(row==n-1)
            return ans;
        
        int ch1 = find(n,m,grid,dp,row+1,col1,col2);
        int ch2 = find(n,m,grid,dp,row+1,col1,col2+1);
        int ch3 = find(n,m,grid,dp,row+1,col1+1,col2+1);
        int ch4 = find(n,m,grid,dp,row+1,col1-1,col2-1);
        int ch5 = find(n,m,grid,dp,row+1,col1,col2-1);
        int ch6 = find(n,m,grid,dp,row+1,col1+1,col2);
        int ch7 = find(n,m,grid,dp,row+1,col1-1,col2);
        int ch8 = find(n,m,grid,dp,row+1,col1-1,col2+1);
        int ch9 = find(n,m,grid,dp,row+1,col1+1,col2-1);
        
        return dp[row][col1][col2]=ans+max(ch1,max(max(ch2,ch3),max(max(ch4,ch5),max(max(ch6,ch7),max(ch8,ch9)))));
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int dp[70][70][70];
        
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                for(int k=0;k<m;++k)
                    dp[i][j][k] = -1;
        
        
        return find(n,m,grid,dp,0,0,m-1);
        
    }
};
