using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MP 55

unsigned int bc[MP][MP];

void binomial_c(){
  memset(bc, 0, sizeof bc);

  for (int n = 0; n < MP; ++n) bc[n][0] = 1;
  for (int n = 1; n < MP; ++n) { bc[n][n] = 1; bc[n][1] = n; }
  for (int n = 3; n < MP; ++n)
    for (int k = 2; k < n; ++k)
      bc[n][k] = (bc[n-1][k-1] + bc[n-1][k]);
}

long long n;
int k;

void mult(const unsigned int a[MP][MP],const unsigned int b[MP][MP], unsigned int c[MP][MP]){
  int t = k+2;

  unsigned int r[MP][MP];
  memset(r, 0, sizeof r);
  for(int i = 0; i < t; ++i){
    for(int j = 0; j < t; ++j){
      r[i][j] = 0;
      for(int p = 0; p < t; ++p)
        r[i][j] += a[i][p] * b[p][j];
    }
  }

  for(int i = 0; i< t; ++i) for (int j = 0; j < t; ++j) c[i][j] = r[i][j];
}


unsigned int A[MP][MP];
unsigned int R[MP][MP];


void mod_pow(long long  n){
  memset(R, 0, sizeof R);for(int i = 0; i < MP; ++i) R[i][i] = 1;
  while(n){
    if(n&1) mult(A,R,R);
    mult(A,A,A);
    n>>=1;
  }
}

unsigned int solve(){
  scanf("%lld%d",&n,&k);
  if(n==1) return 1;

  memset(A, 0, sizeof A);
  for(int i = 0; i <= k; ++i)
    for (int j = 0; j <= i; ++j)
      A[i][j] = bc[i][i-j];
  for(int j = 0; j <= k; ++j)
    A[k + 1][j] = bc[k][k-j];
  A[k+1][k+1] = 1;

  mod_pow(n-1);

  unsigned int ans = 0;
  for (int i = 0; i <= k + 1; ++i)
     ans += R[k+1][i];

  return ans;

}


int main(){ ___
  int tc;scanf("%d",&tc);
  binomial_c();
  for(int i = 0; i < tc; ++i)
    cout<<"Case "<<(i+1)<<": "<<solve()<<endl;

  return 0;
}
