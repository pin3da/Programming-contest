#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

struct seal {
  int x, y;
  seal() {}
  seal(int a, int b) : x(a), y(b) {}
};

seal rotate(seal s) {
  return seal(s.y, s.x);
}

long long area(seal s) {
  return s.x * s.y;
}

bool fit(seal f, seal s, int a, int b) {
  if (f.y <= b && s.y <= b && (f.x + s.x) <= a) return true;
  if (f.x <= a && s.x <= a && (f.y + s.y) <= b) return true;
  return false;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, a, b;
  cin >> n >> a >> b;

  vector<seal> all(n);
  for (auto &i : all) cin >> i.x >> i.y;

  long long best = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      seal f = all[i], s = all[j];
      if (fit(f, s, a, b))
        best = max(best, area(f) + area(s));
      f = rotate(all[i]), s = all[j];
      if (fit(f, s, a, b))
        best = max(best, area(f) + area(s));
      f = all[i], s = rotate(all[j]);
      if (fit(f, s, a, b))
        best = max(best, area(f) + area(s));
      f = rotate(all[i]), s = rotate(all[j]);
      if (fit(f, s, a, b))
        best = max(best, area(f) + area(s));
    }
  }
  cout << best << endl;
  return 0;
}
