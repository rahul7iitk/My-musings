#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define si(X) scanf("%d", &(X))
#define sll(X) scanf("%lld",&(X))
#define INFL 0x3f3f3f3f3f3f3f3fLL

/* -------Template ends here-------- */

const int M = 100001;
vector<int> vec[M];
int dp[M][2];

void dfs(int u , int p){

    dp[u][1] = 1;

    for(int i = 0 ; i<vec[u].size() ; i++){
        int v = vec[u][i];
        if(v == p)
            continue;
        dfs(v , u);
        dp[u][1] += (min(dp[v][0] , dp[v][1]));
        dp[u][0] += (dp[v][1]);
    }

}
int main(){
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);

    int n;
    si(n);

    for(int i = 1 ; i<n ; i++){
        int u , v;
        si(u);  si(v);
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    dfs(1 , 0);
    int ans = min(dp[1][0] , dp[1][1]);
    ans = max(ans , 1);
    cout<<ans;

}