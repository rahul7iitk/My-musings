
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#define big long long
using namespace std;

inline int find_next(int n){
    n+=((~n)+1)&n;
    return n;
}
inline int parent(int n){
    n-=((~n)+1)&n;
    return n;
}
big find_sum(int n,int fenwick[]){
    if(n==0)
        return 0;
    int a=n;big sum=0;
    while(a>0){
        sum+=fenwick[a];
        a=parent(a);
    }
    return sum;
}

int search(string table[],int start,int end,string key){
    if(start>end)
        return -1;
    int mid = (start+end)/2;
    int k = table[mid].compare(key);
    if(k==0)
        return mid;
    if(k>0)
        return search(table,start,mid-1,key);
    else
        return search(table,mid+1,end,key);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    string table[n+1],table_rev[n+1];
    unordered_map<string,string> map;
    for(int i=1;i<=n;i++){
        cin>>table[i];
        string s = table[i];
        reverse(s.begin(),s.end());
        table_rev[i] = s;
        map[table[i]] = s;
    }
    int fenwick[n+1];
    for(int i=0;i<=n;i++)
        fenwick[i] = 0;
    
    sort(table+1,table+n+1);
    sort(table_rev+1,table_rev+n+1);
    //for(int i=1;i<=n;i++)
     //   cout<<table[i]<<" ";
   // cout<<endl;
    //for(int i=1;i<=n;i++)
     //   cout<<table_rev[i]<<" ";
    //cout<<endl;
    big count = 0;
    int index = search(table_rev,1,n,map[table[1]]);
    
    //diff=b-table[a];
   // ++fenwick[index];
    while(index<=n){
        ++fenwick[index];
        index=find_next(index);
    }
    
    for(int i=2;i<=n;i++){
        index = search(table_rev,1,n,map[table[i]]);
        //++index;
        count += find_sum(n,fenwick)-find_sum(index,fenwick);
        
        while(index<=n){
            ++fenwick[index];
            index=find_next(index);
        }
        
    }
    
    cout<<count<<endl;
    return 0;
}













