#include <bits/stdc++.h>

using namespace std;
#define big long long
//const long long min_infinity=-10000000000;

struct segment{
    big prefix_sum,suffix_sum,sum,max_sum;
    struct segment* left;struct segment* right;
};
typedef struct segment* node;
big table[100000];
big size;

void build_tree(big start,big end,node pos){
    if(start==end){
        pos->prefix_sum=pos->suffix_sum=pos->sum=pos->max_sum=table[start];
        pos->left=pos->right=NULL;
        return ;
    }
    big mid=(start+end)/2;
    node a=pos->left=(node)malloc(sizeof(struct segment));
    node b=pos->right=(node)malloc(sizeof(struct segment));
    
    build_tree(start,mid,pos->left);
    build_tree(mid+1,end,pos->right);
    pos->sum=a->sum+b->sum;
    pos->prefix_sum=max(a->prefix_sum,a->sum+b->prefix_sum);
    pos->suffix_sum=max(b->suffix_sum,b->sum+a->suffix_sum);
    pos->max_sum=max(pos->prefix_sum,max(pos->suffix_sum,max(a->max_sum,max(a->suffix_sum+b->prefix_sum,b->max_sum))));
    
}
node query(big start,big end,node pos,big r_start,big r_end){
    if(start>=r_start&&end<=r_end)
        return pos;
        
   else if(end<r_start||start>r_end)
        return NULL;
    
    big mid=(start+end)/2;
    node a=query(start,mid,pos->left,r_start,r_end);
    node b=query(mid+1,end,pos->right,r_start,r_end);
    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;
    
    node p=(node)malloc(sizeof(struct segment));
    p->sum=a->sum+b->sum;
    p->prefix_sum=max(a->prefix_sum,a->sum+b->prefix_sum);
    p->suffix_sum=max(b->suffix_sum,b->sum+a->suffix_sum);
    p->max_sum=max(p->prefix_sum,max(p->suffix_sum,max(a->max_sum,max(a->suffix_sum+b->prefix_sum,b->max_sum))));
    return p;    
}
void update(big start,big end, node pos,big index, big value){
    if(start==end){
        pos->sum=pos->prefix_sum=pos->suffix_sum=pos->max_sum=value;
        return;
    }
    big mid=(start+end)/2;
    if(index<=mid)
        update(start,mid,pos->left,index,value);
    else
        update(mid+1,end,pos->right,index,value);
   node a=pos->left;    
   node b=pos->right;
    pos->sum=a->sum+b->sum;
    pos->prefix_sum=max(a->prefix_sum,a->sum+b->prefix_sum);
    pos->suffix_sum=max(b->suffix_sum,b->sum+a->suffix_sum);
    pos->max_sum=max(pos->prefix_sum,max(pos->suffix_sum,max(a->max_sum,max(a->suffix_sum+b->prefix_sum,b->max_sum))));    
    
}

int main(){
   /* ios::sync_with_stdio(false);
    cin.tie(NULL);*/
  scanf("%lld",&size);
   
   for(big i=0;i<size;i++)
    scanf("%lld",&table[i]);
    
 node root=(node)malloc(sizeof(struct segment));
 root->prefix_sum=root->suffix_sum=root->sum=root->max_sum=0;
    
 build_tree(0,size-1,root);
 big commands; scanf("%lld",&commands);
// cout<<root->prefix_sum<<endl;
 
 node p=NULL;
 while(commands-->0){
     big choice,a,b;
     scanf("%lld %lld %lld",&choice,&a,&b);
     
     switch(choice){
         case 1:
      p=query(0,size-1,root,a-1,b-1);
     printf("%lld\n",p->max_sum);
     break;
     case 0: update(0,size-1,root,a-1,b);
     break;
     }
 }
 return 0;
}
