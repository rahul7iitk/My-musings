#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const ll MOD = 1000000007;
const int MAX = 1000005;
// create a fenwick tree, with rows = number of input values, and columns = 26 , for each lowercase english alphabet
int tree[MAX][30];
// simple summation function for bit, working on a specified alphabet i.e - 'a','b','c' etc
int read(int idx1, int idx2)
{
    int sum = 0;
    while(idx1 > 0)
    {
        sum += tree[idx1][idx2];
        idx1 -= (idx1 & -idx1);
    }
    return sum;
}
// simple update function for bit , working on a specific alphabet
void update(int idx1, int idx2, int val, int n)
{
    while(idx1 <= n)
    {
        tree[idx1][idx2] += val;
        idx1 += (idx1 & -idx1);
    }
}

int main()
{
    int n, q, l, r, idx, k, c, ans;
    char y;
    string s;
    cin >> n >> q >> s;
    
    for(int i = 0;i < n;++i)// for each string character,go to its index in the fenwick tree , and update value by 1.
        //eg - if 'a' is encountered at index = 2, go to tree[2][0] , and increase value by 1.
        update(i + 1, s[i] - 'a', 1, n);
        
    for(int i = 0;i < q;++i)
    {
        scanf("%d", &c);
        if(c)
        {
            scanf("%d %d %d", &l, &r, &k);
            ans = 0; 
            // recurse over all alphabets, starting from 'a' to 'z', and count occurences of that alphabet in range 'l' to 'r'
            // once the total count exceeds k, break. the current alphabet that we are processing is the required answer.
            int j;
            for(j = 0;j < 26;++j)
            {
                ans += read(r, j) - read(l - 1, j);
                if(ans >= k)
                    break;
            }
            if(ans >= k)
                printf("%c\n", j + 'a');
            else printf("Out of range\n");
        }
        else
        {
            // for queries of second type, simply go to index , and the character's position, decrement the value by 1, implying that the character no longer
            // exists at that index, and update the tree with the new character.
            scanf("%d %c", &idx, &y);
            update(idx, s[idx-1] - 'a', -1, n);
            s[idx-1] = y;
            update(idx, s[idx-1] - 'a', 1, n);
        }
    }
    return 0;
}