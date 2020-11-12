class Solution {
public:
    
    #define inf 1000000
    int dp[51][51][51];
    
    int solve(int r1,int c1,int r2,vector<vector<int>> &grid,int n){
        int c2 = r1+c1-r2;
        
        if(r1>=n || c1>=n || r2>=n || c2>=n )
            return -1*inf;
        if(grid[r1][c1]==-1 || grid[r2][c2]==-1)
            return -1*inf;
        
        if(dp[r1][c1][r2]!=-1)
            return dp[r1][c1][r2];
        
        int cost = 0;
        
        if(r1==r2 && c1==c2)
            cost += grid[r1][c1];
        else
            cost += grid[r1][c1]+grid[r2][c2];
        
        if(r1==n-1 && c1==n-1 && r2==n-1)
            return dp[r1][c1][c2]=cost;
        
        int ch1 = solve(r1+1,c1,r2+1,grid,n);
        int ch2 = solve(r1+1,c1,r2,grid,n);
        int ch3 = solve(r1,c1+1,r2,grid,n);
        int ch4 = solve(r1,c1+1,r2+1,grid,n);
        
        dp[r1][c1][r2]=cost + max(ch1,max(ch2,max(ch3,ch4)));
        
        return dp[r1][c1][r2];
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        //int dp[51][51][51];
        memset(dp,-1,sizeof(dp));
        
        int n = grid.size();
        if(grid[0][0]==-1 || grid[n-1][n-1]==-1)
            return 0;
        
        int result = 0;
       // return result;
        result = solve(0,0,0,grid,n);
        
        if(result<0)
            return 0;
        
        return result;
    }
};
