using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 17

int n,m, s,f;

int main() {

  cin>>n>>m>>s>>f;

  int ant = 0;
  int pin = 0;
  string ans;
  if (s < f){
    for (int i = 0; i < m; ++i) {
      int t,l,r;cin>>t>>l>>r;
      int tope = min(t - ant - 1, f - s);
      if (tope > 0) {
        ans += string(tope, 'R');
        s += tope;
      }
      int change = 0;
      if (s == f) break;
      if ((s + 1 < l) or (s > r)) {
        s++;
        ans += 'R';
        change = 1;
      }
      if (!change) ans += 'X';
      if (s == f) break;
      ant = t;
    }
  } else {

    for (int i = 0; i < m; ++i) {
      int t,l,r;cin>>t>>l>>r;
      int tope = min(t - ant - 1, s - f);
      if (tope > 0) {
        ans += string(tope, 'L');
        s -= (tope);
      }
      if (s == f) break;
      int change = 0;
      //D(s);
      //D(l);D(r);
      if ((s - 1 > r) or (s < l)) {
        s--;
        ans += 'L';
        change = 1;
      }
      if (!change) ans += 'X';
      if (s == f) break;
      ant = t;
    }


  }
  while (s != f) {
    if (s > f) {
      s--;
      ans += 'L';
    } else {
      s++;
      ans += 'R';
    }
  }
  cout<<ans<<endl;

  return 0;
}
