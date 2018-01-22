#include <bits/stdc++.h>
using namespace std;

// please read the solution of this problem in folder 'my musings'
#define MOD 1000000007

int dp[1004];
long long ncr[1004][1004];

int ones(int n) // this function is for calculating number of bits set to 1 in number n
{
  int cnt = 0;
  while(n)
  {
    if(n%2 == 1)
    {
      cnt++;
    }
    n /= 2;
  }
  return cnt;
}

void calcncr() // this function is for calculating value of nCr. 
// It uses identity - (n-1)C(r-1)+(n-1)C(r) = nCr So we can calculate nCr for all n<1000 and r<1000 and store in dp
{
  for(int i = 0; i <= 1000; i++)
  {
    ncr[i][0] = 1;
  }
  for(int i = 1; i <= 1000; i++)
  {
    for(int j = 1; j <= 1000; j++)
    {
      ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j])%MOD;
    }
  }
}

int main()
{
  string n;
  int k;
  calcncr();

  dp[1] = 0; // this function store the number of steps taken to convert a number to 1 by counting number of bits set to 1 in it

  for(int i = 2; i <= 1000; i++)
  {
    dp[i] = dp[ones(i)] + 1; // for each i, steps taken for i = 1+steps taken for number equal to bits set in i
  }

  cin >> n >> k;

  if(k == 0)
  {
    cout << "1\n";
    return 0;
  } // only 1 is the number that takes zero steps to convert to 1

  long long nones = 0, ans = 0; // nones basically calculates the number on set bits in n
  for(int i = 0; i < n.size(); i++)
  {
    if(n[i] == '0')
    {
      continue;
    }
    for(int j = max(nones, 1LL); j < 1000; j++)// for each i'th bit set to 1, we already have 'nones' bits set to 1 in n
      // so we need atleast nones number of ones to begine with. That is why max function is used.
    {
      if(dp[j] == k-1)// you can convert any number to j in one step,if it has j number of ones.Overall steps required would be dp[j]+1.
      {
        ans = (ans + ncr[n.size()-i-1][j-nones])%MOD;// first i-1 bits would be same as in 'n', i'th bit in our number should be zero,
        // so we have to place (j-nones) number of 1's in n.size-i-1 places. All such numbers would be smaller than n.
        if(i == 0 && k == 1)
        {
          ans = (ans+MOD-1)%MOD;// if i==0 and k==1, we would also count 1 in our answer. But one would take just zero steps . So we have to subtract from our answer.
        }
      }
    }
    nones++;
  }
  // note that in above steps, the number 'n' has not been analysed . So here we analyse number 'n' itself
  int cnt = 0;
  for(int i = 0; i < n.size(); i++)
  {
    if(n[i] == '1')
    {
      cnt++;
    }
  }
  if(dp[cnt] == k-1)
  {
    ans = (ans + 1)%MOD;
  }
  cout << ans << endl;

  return 0;
}







