#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x " = " << (x) << endl;


struct tri{
  int a, b, c;
  tri() {}
  tri(int x, int y, int z) : a(x), b(y), c(z) {}
  bool operator<(const tri &o) const {
    return a > o.a;
  }
};

int G;

/*void gen(int g, int p, int win, int los, vector<tri> &ans) {
  int de = G  - win - los;
  if (g == 0) {
    if (p == 0)
      ans.push_back(tri(win, de, los));
    return;
  }
  if (p >= 3)
    gen(g - 1, p - 3, win  + 1, los, ans);
  if (p >= 1)
    gen(g - 1, p - 1, win, los, ans);
  
  gen(g - 1, p, win, los + 1, ans);
}*/

void solve() {
  int p;
  cin >> G >> p;
  vector<tri> ans;
  
  cout << "Games: " << G << endl;
  cout << "Points: " << p << endl;
  cout << "Possible records:" << endl;

  for (int i = G; i >= 0; --i) {
    for (int j = G - i; j >= 0; --j) {
      for (int k = G - i - j; k >= 0; --k) {
        if (i + j + k == G) {
          if (3 * i + j == p) {
            cout << i << "-" << j << "-" << k << endl;
          }
        }
      }
    }
  }
}

int main() {
 int tc; cin >> tc;
 for (int i = 0; i < tc; ++i) {
  if (i) cout << endl;
  cout << "Team #" << i + 1 << endl;
  solve();
 }
 return 0;
}
