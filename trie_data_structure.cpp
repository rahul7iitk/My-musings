#include <bits/stdc++.h>

using namespace std;
struct trie{
  struct trie* arr[10];
  bool eow;
};
typedef struct trie* node;
void intialise(node p){
    for(int i=0;i<10;i++)
        p->arr[i]=NULL;
    p->eow=false;    
}
bool find_prefix(node root,string s);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin>>t;
    while(t-->0){
        int n; cin>>n;
        string table[n];
        for(int i=0;i<n;i++)
            cin>>table[i];
        
	string s=table[0];
	
	node root=(node)malloc(sizeof(struct trie));
	intialise(root);
	node start=root;
	
	for(int i=0;i<s.size();i++){
	    int p=s[i]-'0';
	   // cout<<p<<endl;
	    start->arr[p]=(node)malloc(sizeof(struct trie));
	    start=start->arr[p];
	    intialise(start);
	}
	start->eow=true; bool result=false;
	
	for(int i=1;i<n;i++){
	    s=table[i];
	    result=find_prefix(root,s);
	    if(result)
	        break;
	}
	if(result)
	    cout<<"NO"<<endl;
	else
	    cout<<"YES"<<endl;
	
    }
	
	return 0;
}
bool find_prefix(node root,string s){
    node start=root,temp; bool ans=true;
    
    for(int i=0;i<s.size();i++){
        int p=s[i]-'0';
        if(start->eow)
            return true;
        if(start->arr[p]==NULL){
            ans=false;
            temp=start->arr[p]=(node)malloc(sizeof(struct trie));
            intialise(temp);
            start=temp;
        }
        else
        start=start->arr[p];
    }
    start->eow=true;
    return ans;
}
