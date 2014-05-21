// Por terminar !!

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl


const int MN = 10001;

int m,k;
string line;

long long memo[66][66][2];

const long long inf = 1e18;

long long dp(int index, int cuenta, int tope) {
  if (index == line.size()) return cuenta == k;

  if (memo[index][cuenta][tope] != -1) return memo[index][cuenta][tope];

  long long ans = dp (index + 1, cuenta, tope);
  if (!tope) {
    if (index == 0) tope = line[0] == '1';
    ans = ans + dp(index +1 , cuenta + 1, tope and line[index] == '1');
  }

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
  long long aa = dp(0,0,0);

  long long b = n<<1;

  memset(memo, -1, sizeof memo);
  line = fun (b);
  long long bb = dp(0,0,0);

  return bb - aa;
}

int main() { ___

  cin>>m>>k;

  /*if (m == 1 and k == 1){
    cout<<1<<endl;
    return 0;
  }
  long long lo = 0;
  long long hi = inf;

  while (lo < hi) {

    long long mid  = (lo + hi)>>1;

    if (lo + 1 == hi) {
      lo = hi;
      break;
    }

    if (cuenta(mid) < m) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }

  cout<<((lo + hi)>>1)<<endl;*/

  for (long long i = 1; i <= inf; ++i) {
    D(cuenta(i));
    if (cuenta(i) == m){
      cout<<i<<endl;
      return 0;
    }
  }

  return 0;
}


