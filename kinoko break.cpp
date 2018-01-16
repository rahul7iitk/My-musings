#include <iostream>
#include <cstdio>
#include <unordered_map>
using namespace std;
const int limit = 100010;
int table[limit];
pair<int,int> arr[limit];
bool is_filled[limit];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i)
        cin>>table[i];
    unordered_map<int, int> hash1;
    unordered_map<int, int> hash2;
    for(int i=1;i<=m;++i)
        is_filled[i] = false;
    for(int i=1;i<=m;++i)
        cin>>arr[i].first>>arr[i].second;
    int i=0,start = -1,end = 0,count = 0; long long total = 0;
    for(;i<n;++i){
        while(start<n){
            if(count==m)
                break;
            ++start;
            if(start>n-1)
                break;
            if(hash1[table[start]]+1==arr[table[start]].first){
                is_filled[table[start]] = true;
                 ++hash1[table[start]];
                if(count<m)
                ++count;
            }
             else
                  ++hash1[table[start]];
        }
        while(end<n){
            if(hash2[table[end]]+1>arr[table[end]].second)
                break;
            ++hash2[table[end]];
            ++end;
        }
        if(end>start)
        total += end-start;
        
        if(hash1.find(table[i])!=hash1.end())
            --hash1[table[i]];
        if(hash2.find(table[i])!=hash2.end())
            --hash2[table[i]];
        if(hash1[table[i]]<arr[table[i]].first && is_filled[table[i]]){
            is_filled[table[i]] = false;
            --count;
        }
       
    }
    cout<<total<<"\n";
    return 0;
}






























