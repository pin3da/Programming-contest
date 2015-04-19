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

int main(){IO;
  int n;
  cin >> n;

  vi v(n);
  REP(i,n) cin >> v[i];

  vi pos(n+1);
  REP(i,n){
    pos[v[i]] = i;
  }

  int q;
  cin >> q;

  vlld dp(n+1);
  vi mark(n+1);

  REP(ii,q){
    int k;
    cin >> k;

    if(dp[k] == 0){
      lld ans = 0;

      rep(jj,1,n+1){
        if(k * jj > n) break;
        if(mark[k * jj] == k) continue;
        mark[k * jj] = k;

        int p = pos[k * jj];
        int i = p - 1;
        int j = p + 1;
        lld cnt = 1;
        while(i >= 0){
          if(v[i] % k == 0){
            mark[v[i]] = k;
            cnt++;
            i--;
          }else{
            break;
          }
        }

        while(j < n){
          if(v[j] % k == 0){
            mark[v[j]] = k;
            cnt++;
            j++;
          }else{
            break;
          }
        }

        ans += (cnt * (cnt + 1)) / 2;
      }
      dp[k] = ans;
    }

    cout << dp[k] << endl;
  }

  return 0;
}

