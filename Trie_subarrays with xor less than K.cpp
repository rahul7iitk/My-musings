#include <iostream>
#include <cstdio>
#define big long long
struct trie{
    big size;
    struct trie* left;
    struct trie* right;
};
typedef struct trie* node;
const int bit_size = 32;
node allocate(){
    node p = (node) malloc(sizeof(struct trie));
    p->size = 0;
    p->left = NULL;
    p->right = NULL;
    return p;
}
void insert(node root,int value,int i){
    if(i<0){
        ++root->size ;
        return;
    }
    bool val = value & (1<<i);
    if(val){
        if(!root->right)
            root->right = allocate();
        insert(root->right, value, i-1);
    }
    else {
        if(!root->left)
        root->left = allocate();
    insert(root->left, value, i-1);
    }
    root->size = 0;
    if(root->left)
        root->size += root->left->size;
    if(root->right)
        root->size += root->right->size;
    return;
}
big result,result2 ;
void less_than(int k,int i,node root,int value){
    if(i<0)
        return;
    bool k_bit = k & (1<<i);
    bool val_bit = value & (1<<i);
    if(val_bit && k_bit)
    {  if(root->right)
        result += root->right->size;
        if(root->left)
            less_than(k, i-1, root->left, value);
    }
    if(!val_bit && k_bit){
        if(root->left)
        result += root->left->size;
        if(root->right)
            less_than(k, i-1, root->right, value);
    }
    if(val_bit && !k_bit)
    {
        if(root->right)
            less_than(k, i-1, root->right, value);
    }
    if(!val_bit && !k_bit){
        if(root->left)
            less_than(k, i-1, root->left, value);
    }
    return;
}

int main() {
    int t; scanf("%d",&t);
    while(t-->0){
        node root = allocate();
        int n,k; scanf("%d %d",&n,&k);
        result = 0;
        int value = 0; int running_xor = 0;
        insert(root, running_xor, bit_size-1);
        for(int i=0;i<n;++i)
        {
            scanf("%d",&value);
            running_xor = running_xor^value;
            less_than(k, bit_size-1, root, running_xor);
            insert(root, running_xor, bit_size-1);
        }
        printf("%lld\n",result);
    }
    return 0;
}














