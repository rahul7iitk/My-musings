#include <bits/stdc++.h>


using namespace std;
int find_mod(string s,int n){
    int result = 0;
    for(int i=0;i<s.size();i++){
        int k = s.at(i)-'0';
        result = (result*10+k)%n;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
	int t; cin>>t;
	//cout<<find_mod("596",10)<<endl;
	
	while(t-->0){
	    int n; cin>>n;
	    if(n==1)
	    {
	        cout<<1<<endl;
	        continue;
	    }
	    
	    int table[n];
	    for(int i=0;i<n;i++)
	        table[i] = -1;
	        
	    queue<string> que;
	    que.push("1");
	    table[1] = 1;
	    
	   // cout<<"hello"<<endl;
	   while(!que.empty()){
	        
	        string s = que.front();
	        
	        que.pop();
	      string s1 = s+"0";
	        int k = find_mod(s1,n);
	        if(table[k]==-1)
	            {
	                table[k] = find_mod(s,n);
	                que.push(s1);
	            }
	        s1 = s+"1";
	        k = find_mod(s1,n);
	        if(table[k]==-1)
	            {
	                table[k] = find_mod(s,n);
	                que.push(s1);
	            }
	        if(table[0]!=-1)
	            break;
	    } 
	    string ans=""; int i = 0;
	    while(i!=1){
	        int k = table[i];
	        if((k*10)%n==i)
	            ans = "0"+ans;
	        else
	            ans = "1"+ans;
	        i = k;     
	    }
	    ans = "1"+ans;
	    cout<<ans<<endl;        
	}
	return 0;
}
