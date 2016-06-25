#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS){
    return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct ing {
  string name;
  double w, p;
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int tc; cin >> tc;
  int tid = 0;
  cout << fixed << setprecision(1);
  while (tc--) {
    int r, j = 0, id = -1;
    double p, d;
    cin >> r >> p >> d;
    double ratio = d;
    vector<ing> ingred(r);
    for (auto &i : ingred) {
      cin >> i.name >> i.w >> i.p;
      if (cmp(i.p, 100) == 0) {
        assert(id == -1);
        id = j;
      }
      j++;
    }
    assert(id != -1);
    double ratio2 = ingred[id].w * ratio;

    for (int i = 0; i < r; ++i) {
      ingred[i].w = ingred[i].p * ratio2 / (p * 100.0);
    }
    cout << "Recipe # " << ++tid << endl;
    for (auto &i : ingred) {
      cout << i.name << ' ' << i.w  + EPS << endl;
    }
    cout << string(40, '-') << endl;
  }

  return 0;
}
