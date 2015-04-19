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

int main(){
  int t;
  cin >> t;

  REP(i,t){
    int n, k;
    cin >> n >> k;

    int g = 0;
    REP(i,n){
      int s;
      cin >> s;
      if(s % k == 0){
        if(g == 0) g = s;
        else g = __gcd(g, s);
      }
    }

    if(g == k) cout << "YES" << endl;
    else cout << "NO" << endl;
  }

  return 0;
}

