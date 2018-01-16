#include<cstdio>
#define big long long

big tree[408000];
big lazy[408000];


void update(big node, big st, big en, big a, big b,big value){
    if(lazy[node]){
        
        tree[node] += (en-st+1)*lazy[node];
        if(st<en){
            lazy[node<<1] += lazy[node];
            lazy[1+(node<<1)] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(st>en || a > en || b < st) return ;
    if(a<=st && en<=b){
        tree[node] += (en-st+1)*value;
        if(st<en){
            lazy[node<<1] += value;
            lazy[1+(node<<1)] += value;
        }
        return;
    }
    big mid = (st+en)/2;
    update((node<<1),st,mid,a,b,value);
    update((node<<1)+1,mid+1,en,a,b,value);
    if(st<en) tree[node] = tree[node<<1] + tree[(node<<1)+1];
}

big query(big node, big st, big en, big a, big b){
    
    if(st>en || a > en || b < st) return 0;
    
    if(lazy[node]){
        
        tree[node] += (en-st+1)*lazy[node];
        
        if(st<en){
            lazy[node<<1] += lazy[node];
            lazy[1+(node<<1)] += lazy[node];
        }
        lazy[node] = 0;
    }
    
    if(a<=st && en<=b){
        return tree[node];
    }
    big mid = (st+en)/2;
    big t1 = 0, t2 = 0;
    t1 = query((node<<1),st,mid,a,b);
    t2 = query((node<<1)+1,mid+1,en,a,b);
    return t1+t2;
}


int main(){
    big n,m,q,a,b,t,value;
    
    scanf("%lld",&t);
    while(t-->0){
        for(big i=0;i<408000;i++)
        {
            tree[i]=lazy[i]=0;
        }
        scanf("%lld %lld",&n,&m);
        while(m--){
            scanf("%lld %lld %lld",&q,&a,&b);
            if(q==1) printf("%lld\n",query(1,1,n,a,b));
            else
            {   scanf("%lld",&value);
                update(1,1,n,a,b,value);
            }
        }
    }
    return 0;
}

