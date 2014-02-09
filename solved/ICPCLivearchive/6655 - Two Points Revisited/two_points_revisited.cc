using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MP 1010

int t;
const double pi  = acos(-1.0);
const double eps = 1e-9;

struct PT {
  long long x, y;
  PT() {}
  PT(long long x, long long y) : x(x), y(y) {}

};

PT RotateCW90(PT p)    { return PT(p.y,-p.x); }


void solve() {

  int a,b,c,d;
  cin>>a>>b>>c>>d;
  PT vec(c-a, d-b);
  vec = RotateCW90(vec);

  double m = ((vec.y) ?  (vec.x / (double)vec.y) : 1.0);


  cout<<"Case "<<t<<": ";
  if (m < 0) {
    if (vec.x < 0) vec.x *= -1;
    if (vec.y < 0) vec.y *= -1;
    cout<<vec.x<<" 0 0 "<<vec.y<<endl;

  } else {
    if (vec.x < 0) vec.x *= -1;
    if (vec.y < 0) vec.y *= -1;
    cout<<"0 0 "<<vec.x<<" "<<vec.y<<endl;
  }


}

int main() { ___
  int tc;cin>>tc;
  for (t = 1; t <= tc; ++t)
    solve();

  return 0;
}
