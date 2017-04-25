// http://codeforces.com/contest/385/problem/C

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for(int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MM 10000010

int sieve[MM], frec[MM];
long long ii[MM];
int n;
void fill_sieve() {
  memset(sieve, 0, sizeof sieve);
  memset(ii, 0, sizeof ii);

  sieve[0] = sieve[1] = 1;

  for (int i = 2; i < MM; ++i) {
    if (!sieve[i]) {
      int ans = frec[i];
      for (int j = i + i; j < MM; j += i) {
        sieve[j] = true;
        ans += frec[j];
      }
      ii[i] = ans;
    }
  }
  for (int i = 1; i < MM; ++i) ii[i] += ii[i - 1];
}

int main() { ___
  cin>>n;
  int t;
  memset(frec, 0, sizeof frec);
  for (int i = 0; i < n; ++i) {
    cin>>t;
    frec[t]++;
  }

  fill_sieve();

  int m;cin>>m;
  while (m-- ) {
    long long r,l;cin>>l>>r;
    r = min ( 10000000LL, r);
    l = min ( 10000000LL, l);
    cout<<(ii[r] - ii[l - 1])<<endl;
  }

  return 0;
}