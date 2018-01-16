#include <iostream>

using namespace std;
struct block{
    int pointer;
    int size;
};
typedef struct block node;

int find(node table[],int a){
    while(table[a].pointer!=a)
        a = table[a].pointer;
        
    return a;    
}

void do_union(node table[],int a,int b){
   int a_parent = find(table,a);
   int b_parent = find(table,b);
   
   if(a_parent == b_parent)
    return ;
   
   if(table[a_parent].size>table[b_parent].size){
       table[b_parent].pointer = a;
       table[a_parent].size += table[b_parent].size;
   }
   else{
       table[a_parent].pointer = b;
       table[b_parent].size += table[a_parent].size;
   }
   
}

int main() {
    // take the number of elements
    int n; cin>>n;
    int table[n];
    
    for(int i=0;i<n;i++)
        cin>>table[i];
        
    // creating the array of blocks
    node table1[n];
    for(int i=0;i<n;i++){
        table1[i].pointer = i;
        table1[i].size = 1;
    }
    
    // take the number of queries 
    int q; cin>>q;
    while(q-->0){
        int a,b,c;
        cin>>a;
        // if query starts with one, it means union, if it start with 0, it means find
        switch(a){
            
            case 0:
            cin>>b;
            cout<<find(table1,b)<<endl;
            break;
            
            case 1:
            cin>>a>>b;
            do_union(table1,a,b);
        }
        
    }
    return 0;
}
