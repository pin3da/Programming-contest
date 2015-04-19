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

lld modpow(lld x, int e, lld n){
  lld ans = 1;
  lld b = x;
  REP(i,30){
    if((e >> i) & 1){
      ans = (ans * b) % n;
    }
    b = (b * b) % n;
  }
  return ans;
}

lld egcd(lld a, lld b, lld &x, lld &y) {
  lld xx = y = 0;
  lld yy = x = 1;
  while (b) {
    lld q = a/b;
    lld t = b; b = a%b; a = t;
    t = xx; xx = x-q*xx; x = t;
    t = yy; yy = y-q*yy; y = t;
  }
  return a;
}

lld solve(lld a, lld b, lld n){
  lld m = ceil(sqrt(n));
  lld aj = 1;
  map<lld, lld> M;
  REP(j,m){
    if(M.count(aj) == 0){
      M[aj] = j;
    }
    aj = (aj * a) % n;
  }

  lld inva, t;
  egcd(a, n, inva, t);
  inva = (inva + n) % n;

  lld coe = modpow(inva,m,n);
  lld y = b;

  REP(i,m){
    if(M.count(y)){
      lld j = M[y];
      return i * m + j;
    }else{
      y = (y * coe) % n;
    }
  }
  return -1;
}

int main(){
  int t;
  cin >> t;

  REP(i,t){
    lld a, b, g;
    cin >> a >> b >> g;
    lld x = solve(a, b, g);
    cout << x << endl;
  }

  return 0;
}

