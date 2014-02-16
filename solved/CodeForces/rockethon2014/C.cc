using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 17

int table[MN][MN];
int points[MN], effort[MN];

struct man{
  int p, win;
  man(){}
  man(int a, int c): p(a) , win(c){}

  bool operator < (const man & o) const {
    if (p == o.p)  return table[win][o.win];
    return p > o.p;
  }
};

int main() { ___

  int n,k;

  cin>>n>>k;

  for (int i = 0; i <  n; ++i) {
    cin>>points[i]>>effort[i];
  }

  int ans = 1<<30;
  for (int mask = 0; mask < (1<<n); ++mask) {
    int amount = 0, mp = 0;
    man oponent;
    vector<man> all;
    memset(table, 0, sizeof table);

    for (int i = 0; i < n; ++i) {
      if ((mask>>i) & 1) {
        amount += effort[i];
        oponent.p = points[i];
        oponent.win = i;
        mp++;
        table[n][i] = 1;
      } else {
        oponent.p = points[i] + 1;
        oponent.win = i;
        table[i][n] = 1;
      }
      all.push_back(oponent);
    }
    all.push_back(man(mp,n));
    sort(all.begin(), all.end());
    int pos;
    for (int i = 0; i < all.size(); ++i) {
      if(all[i].win == n) {
        pos = i + 1;
        break;
      }
    }
    //D(pos);

    if (pos <= k) {
      ans = min(ans, amount);
    }
  }

  if (ans == (1<<30)) cout<<-1<<endl;
  else cout<<ans<<endl;

  return 0;
}
