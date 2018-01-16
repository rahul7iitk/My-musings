#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <ctype.h>
#include <stack>
#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <iterator>
 
 
using namespace std;
// this is a common node for both queries and array values.
// queries are of the form (i',j',k)
struct node{
    int v; // value of array element , or 'k' value for the queries.
    int i; // index position for array values, i' values for queries
    int j; // -1 for array values, j' for queries
    int q; // query index for queries(original location to print queries in the right format)
};
 
typedef node node;
 
int tree[30001];
node inp[230000];
int n;
int maxVal;

// sorting operator for sorting both array and query values together
bool operator <( node a, node b ) {
    if ( a.v == b.v ) { 
        return a.j > b.j;
    }
    return a.v > b.v;
}
 
 
 // simple sum function for bit
int read(int idx){
    int sum = 0;
    while(idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
// simple update function for bit
void update(int idx, int val){
    while(idx <= maxVal){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}
 
int main()
{
    int m;
    scanf("%d", &n);
    maxVal = n;
    for(int i = 0 ; i < n ; i++){
        // here we are taking input array values
        scanf("%d", &inp[i].v);
        inp[i].i = i + 1; // setting index for array values, i+1 because of binary tree :) you know bit starts with 1
        inp[i].j = -1; // set j=-1 to seperate arrays values from queries
        tree[i] = 0; // preallocation for bit
    }
    scanf("%d", &m);
    int res[m];
 
    for(int i = 0 ; i < m ; i++){
        // here we are taking input query values
        scanf("%d %d %d", &inp[i + n].i , &inp[i + n].j, &inp[i + n].v); // setting i = i' , j=j', and value = k for each query
        inp[i + n].q = i; // storing query position for each query 
    }
 
    sort( inp, inp + n + m ); // sort both array and query values together in decreasing order
 
 
    for(int i = 0 ; i < n + m ; i++){
        if(inp[i].j == -1){ // if you encounter an array value(j = -1), simply increase bit at index = original position of value encountered by 1
            update(inp[i].i, 1);
        }else{
            // for query values, you just need to calculate the number of array values encounter till now from i' to j'. this is because
            // we have sorted everything in descending order, so all values which we have found till now will be larger than k and this is what we have to calculate
            int result = read(inp[i].j) - read(inp[i].i - 1);
            res[inp[i].q] = result;
        }
    }
 
    for(int i = 0 ; i < m ; i++)
        printf("%d\n", res[i]);
    return 0;
}