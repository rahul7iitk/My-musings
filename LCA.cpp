#include <iostream>
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int MAX = 1010;

int dp[12][MAX];
vector<vector<int>> graph(MAX);
int level[MAX];

int ln(int n){
    int count = 0;
    while(n>0){
        n = n/2;
        ++count;
    }
    return count-1;
}
void dfs(int node,int a){
    level[node] = a;
    
    for(int i=0;i<graph[node].size();++i)
            dfs(graph[node][i],a+1);
    return;
}
int lca(int u,int v,int dp[][MAX],int level[]){
    
    if(level[v]<level[u]){
        int temp = u;
        u = v;
        v = temp;
    }
    
    int diff = level[v]-level[u];
    
    while (diff > 0) {
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
        while (u != v) {
            int i = ln(level[u]);
            for (; i > 0 && dp[i][u] == dp[i][v]; )
                i--;

            u = dp[i][u];
            v = dp[i][v];
        }
        return u;
    
}
int main()
{
    
    
    int t; scanf("%d",&t);
    
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
        
        dfs(root,0);
        
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
