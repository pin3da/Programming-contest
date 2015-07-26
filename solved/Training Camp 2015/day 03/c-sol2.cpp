// Alternative solution for problem C
// Author: Lech Duraj

#include <cstdio>
#include <algorithm>
#include <cassert>

using namespace std;

const int maxn = 200*1000;
const int maxlog = 20;

typedef long long LL;

LL A[maxn+1];
LL B[maxlog][maxn+1];


LL gcd(LL x, LL y)
{
  if (x<y)
    return gcd(y,x);
  if (y==0)
    return x;
  return gcd(y,x%y);
}

LL query(int p, int q)
{
  int x = 0;
  while(p+(1<<x)<=q+1)
    x++;
  x--;
  int d = 1 << x;
  return gcd(B[x][p],B[x][q-d+1]);;
}

int main()
{
  int TT;
  scanf("%d",&TT);
  while(TT--)
  {
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
      scanf("%Ld",&A[i]);
      B[0][i] = A[i];
    }
    A[n] = B[0][n] = 1;
    int k = 1;
    while((1<<k)<=n)
    {
      int d = 1 << (k-1);
      for(int i=0; i+2*d<=n+1; i++)
        B[k][i] = gcd(B[k-1][i],B[k-1][i+d]);
      k++;
    }
    long long best = 1;
    for(int i=0; i<n; i++)
    {
      int j = i;
      long long current = A[i];
      while(j<n)
      {
        int p = j;
        int q = n-1;
        while(p<q)
        {
          int s = (p+q+1)/2;
          if (query(i,s)==current)
            p = s;
          else
            q = s-1;
        }
        best = max(best, current*(p-i+1));
        j = p+1;
        if (j<n)
          current = query(i,j);
      }
    }
    printf("%Ld\n",best);
  }
}
