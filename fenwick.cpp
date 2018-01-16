#include <iostream>

using namespace std;

inline int find_next(int n){
     n+=((~n)+1)&n;
     return n;
}
inline int parent(int n){
     n-=((~n)+1)&n;
     return n;
}
int find_sum(int n,int fenwick[]){
    if(n==0)
        return 0;
    int a=n,sum=0;
    while(a>0){
        sum+=fenwick[a];
        a=parent(a);
    }
    return sum;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
   int n; cin>>n;
   int table[n+1];
   
   for(int i=1;i<=n;i++)
    cin>>table[i];
    
   int fenwick[n+1];
   for(int i=0;i<=n;i++)
    fenwick[i]=0;
   
   for(int i=1;i<=n;i++){
       int a=i; fenwick[a]+=table[i];
       while(a<=n){
           a=find_next(a);
           fenwick[a]+=table[i];
       }
   }
  /* int index; cin>>index;
   cout<<fenwick[index]<<endl;*/
   
   int commands; cin>>commands;
   while(commands-->0){
       int choice,a,b; cin>>choice;cin>>a>>b;int diff=0;
       
       switch(choice){
           case 0: 
            diff=b-table[a];
           fenwick[a]+=diff;
           while(a<=n){
               a=find_next(a);
               fenwick[a]+=diff;
           }
           break;
           case 1:
           cout<<find_sum(b,fenwick)-find_sum(a-1,fenwick)<<endl;
           
           break;
       }
   }
   return 0;
}
