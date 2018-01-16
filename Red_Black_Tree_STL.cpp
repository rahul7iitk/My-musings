/* This code is STL implementation of Red Black Binary Trees,
supporting insertion,deletion,finding etc operations in log(n) time 
*/

#include <bits/stdc++.h>
// the below headers are important to implement red black trees , namely associative containers and policy based structures
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

// this is another namespace required by us
using namespace __gnu_pbds;

/* this is the tree container , less<int> is for arranging in ascending order
rb_tree_tag is for red black tree, 
*/
typedef tree<
int ,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>pbd_set;

int main(){
    pbd_set s;
    int t;
    scanf("%d ",&t);
    /* here we are supporting 4 operations,'I' is for inserting an element,
    note that if an element is already in the tree, the tree will not include it again
    'D' is for deleting the element n, 'K' is for finding the n'th largest element in
    the tree, the find_by_order function does this task, returning the iterator to the
    required element. order_of_key element returns the index of element in the tree,
    starting from 0, in the sorted order of elements. 
    */
    while(t--){
        char typ;
        int n;
        scanf(" %c%d",&typ , &n);
        if(typ == 'I')
            s.insert(n);
        else if (typ == 'D')
            s.erase(n);
        else if (typ == 'K'){
            int ans;
            n--;
            if(s.find_by_order(n) != s.end()){
                ans = *s.find_by_order(n);
                printf("%d\n",ans);
            }
            else 
                printf("invalid\n");
        }
        else{
            int ans = s.order_of_key(n);
            printf("%d\n",ans);
        }
    }
    return 0;
}
