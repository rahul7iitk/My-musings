
#include <iostream>
#include <cstdio>

struct trie{
    int final_value;
    struct trie* left;
    struct trie* right;
};
typedef  struct trie* node;
const int bit_size = 32;

node allocat(){
    node p = (node)malloc(sizeof(struct trie));
    p->left = NULL;
    p->right = NULL;
    p->final_value = 0;
    return p;
}
node insert(node root,int value){
    node ptr = root;
    for(int i=bit_size-1;i>=0;--i){
        int val = value & (1<<i);
        if(val){
            if(ptr->right==NULL)
                ptr->right = allocat();
            ptr = ptr->right;
        }
        else{
            if(ptr->left==NULL)
                ptr->left = allocat();
            ptr = ptr->left;
        }
    }
    ptr->final_value = value;
    return root;
}
int query(node root,int value){
    node start = root;
    for(int i=bit_size-1;i>=0;--i){
        int val = value & (1<<i);
        if(val){
            if(start->left!=NULL)
                start = start->left;
            else
                start = start->right;
        }
        else{
            if(start->right!=NULL)
                start = start->right;
            else
                start = start->left;
        }
    }
    return value^(start->final_value) ;
}

int main() {
    int t; scanf("%d",&t);
    while(t-->0){
        node root = allocat();
        int n; scanf("%d",&n);
        int value;
        scanf("%d",&value);
        root = insert(root, 0);
        root = insert(root, value);
        int running_xor = value;
        int max_value = value;
        for(int i=1;i<n;++i){
            scanf("%d",&value);
            running_xor = running_xor^value;
            root = insert(root, running_xor);
            int result = query(root, running_xor);
            if(result>max_value)
                max_value = result;
        }
        printf("%d\n",max_value);
    }
    return 0;

    }













