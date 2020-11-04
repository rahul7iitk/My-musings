#include <iostream>
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/**** Source Gaurav Sen's video on LCA using dynamic programming ***/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int MAX = 1010; // Maximum number of nodes in tree. Change according to requirement

int dp[12][MAX]; // log(1000) is approx 12. Change accordingly
vector<vector<int>> graph(MAX); // your graph
int level[MAX]; // stores the level or distance/depth from the root of each vertex

int ln(int n){ // simple function to calculate number of binary digits in a number minus 1
    int count = 0;
    while(n>0){
        n = n/2;
        ++count;
    }
    return count-1;
}
void dfs(int node,int a){ // simple dfs which just finds the depth/distance of each vertex from root. Make changes accordingly
    level[node] = a;
    
    for(int i=0;i<graph[node].size();++i)
            dfs(graph[node][i],a+1);
    return;
}
int lca(int u,int v,int dp[][MAX],int level[]){ // Main function for finding LCA
    
    if(level[v]<level[u]){ 
        int temp = u;
        u = v;
        v = temp;
    }
    
    int diff = level[v]-level[u];
    
    while (diff > 0) {  // This function is simply for getting both u and v upto same level.In each iteration you jump upwards and update diff
            int l = ln(diff);
            v = dp[l][v];
            diff -= (1 << l);
        } 
        /*
    while (u != v) {
            int i = ln(level[u]);
            for (; i > 0 && dp[i][u] == dp[i][v]; )
                i--;

            u = dp[i][u];
            v = dp[i][v];
        }
        */
        while (u != v) { // you start with the highest jump, if dp[i][u]==dp[i][v],means either you have surpased LCA or are at LCA.
          // So you decrease the jump height, untill dp[i][u]!=dp[i][v]. As soon as u reach it, you update u and v and continue again.
            int i = ln(level[u]);
            for (; i > 0 && dp[i][u] == dp[i][v]; )
                i--;

            u = dp[i][u];
            v = dp[i][v];
        }
        return u; // when you exit loop , both u and v are at lca
    
}
int main()
{
    
    
    int t; scanf("%d",&t); // problem specific jargon, make changes accordingly
    
    for(int p=1;p<=t;++p){
        int n; scanf("%d",&n);
        
        for(int i=1;i<=n;++i){
            dp[0][i] = i;
            graph[i].clear();
            level[i] = i;
        }
            
        
        for(int i=1;i<=n;++i){
            int k; cin>>k;
            for(int j=0;j<k;++j)
                {
                    int u; scanf("%d",&u);
                    dp[0][u] = i;
                    graph[i].push_back(u);
                }
        }
        int level_max = ln(n);
        
        int root = 1;
        
        dfs(root,0); // here root is 1. Run dfs from root to get parent of each vertex i.e dp[0][u] for all u, also distance of each vertex from root
        
      // main iteration. 
        for(int i=1;i<=level_max;++i)
            for(int j=1;j<=n;++j)
                dp[i][j] = dp[i-1][dp[i-1][j]];
        
        int q; scanf("%d",&q); printf("Case %d:\n",p);
        while(q-->0){
            int a,b; cin>>a>>b;
            printf("%d\n",lca(a,b,dp,level));
        }
        
    }
    return 0;
}
