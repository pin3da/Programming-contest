#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

struct st {
  int f, s;
  st() {}
  st(int a, int b): f(a), s(b) {}
  bool operator < (const st &o ) const {
    if (f == o.f)
      return s > o.s;
    return f < o.f;
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  int first = 1;
  while (cin >> line) {
    if (!first)
      cout << endl;
    first = false;
    vector<int> f(1000);
    for (auto &i : line) f[i]++;
    vector<st> ans;
    for (int i = 0; i < f.size(); ++i)
      if (f[i] > 0)
        ans.emplace_back(f[i], i);

    sort(ans.begin(), ans.end());
    for (auto &i : ans)
      cout << i.s << ' ' << i.f << endl;
  }

  return 0;
}
