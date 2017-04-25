// http://codeforces.com/contest/431/problem/D

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl


const int MN = 10001;

long long m,k;
string line;

long long memo[66][66][2];

const long long inf = 1e18;

long long dp(int index, int cuenta, int tope) {
  if (index == line.size()) return cuenta == k;
  if (memo[index][cuenta][tope] != -1) return memo[index][cuenta][tope];
  long long ans = 0;
  if (tope) {
    if (line[index] == '1')
      ans = dp(index + 1, cuenta + 1, 1) + dp(index + 1, cuenta, 0);
    else
      ans = dp(index + 1, cuenta, 1) ;
  }
   else
    ans = dp(index + 1, cuenta + 1, 0) + dp(index + 1, cuenta, 0) ;
  return memo[index][cuenta][tope] = ans;
}

string fun( long long n) {
  string ans;
  while(n) {
    if (n & 1LL)
      ans = '1' + ans;
    else
      ans = '0' + ans;
    n>>=1;
  }
  return ans;
}

long long cuenta(long long n) {
  long long a = n;
  memset(memo, -1, sizeof memo);
  line = fun (a);
  long long aa = dp(0,0,1);
  long long b =  n << 1;
  memset(memo, -1, sizeof memo);
  line = fun (b);
  long long bb = dp(0,0,1);
  return bb - aa;
}

int main() { ___

  cin>>m>>k;

  long long lo = 1;
  long long hi = inf;

  while (lo <= hi) {

    long long mid  = (lo + hi)>>1;
    long long cmid = cuenta(mid);
    if (cmid == m) {
      cout<<mid<<endl;
      return 0;
    }
    if (cuenta(mid) < m)
      lo = mid + 1;
    else
      hi = mid - 1;
  }

  return 0;
}


