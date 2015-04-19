#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define rep(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define repd(i,a,b) for(int (i)=(b)-1;(i)>=(a);(i)--)
#define REP(i,n) rep(i,0,n)
#define REPD(i,n) repd(i,0,n)
#define pb push_back
#define mp make_pair
#define countbits(x) __builtin_popcount(x)
#define countbitslld(x) __builtin_popcountll(x)

typedef long long int lld;
typedef vector<int> vi;
typedef vector<lld> vlld;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

const int maxn = 2000005;

vi f(int maxn){
  vi mark(maxn);
  rep(i,2,maxn) if(mark[i] == 0){
    mark[i] = i;
    lld t = i; t *= i;
    while(t < maxn){
      mark[t] = i;
      t += i;
    }
  }
  return mark;
}

lld calc(vi &v, int n){
  lld sum = 0;
  while(n > 1){
    sum += v[n];
    n /= v[n];
  }
  return sum;
}


int main() {
  int t;
  cin >> t;

  vi v = f(maxn);

  lld ans = 0;
  REP(i,t){
    int n;
    cin >> n;
    lld sum = calc(v, n);
    ans += sum;
  }
  cout << ans << endl;

  return 0;
}



