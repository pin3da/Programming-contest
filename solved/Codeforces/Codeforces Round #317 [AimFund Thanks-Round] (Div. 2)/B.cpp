// http://codeforces.com/contest/572/problem/B

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

struct order{
  int t, p, s;
  bool operator < (const order &o) const {
    if (t == o.t) {
      return p > o.p;
    }
    return t < o.t;
  }
};

void solve(int n, int s) {
  map<pair<char, int>, int> m;
  char a;
  int b, c;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b >> c;
    m[make_pair(a, b)] += c;
  }

  vector<order> t;
  for (auto &it : m) {
    t.push_back((order){it.first.first != 'S', it.first.second, it.second});
  }
  sort(t.begin(), t.end());

  vector<order> first, second;
  for (int i = 0; i < t.size(); ++i) {
    if (t[i].t) second.push_back(t[i]);
    else first.push_back(t[i]);
  }

  int i = 0;
  if (s < first.size())
    i = first.size() - s;
  for (; i < first.size(); ++i)
    cout << "S " << first[i].p << " " << first[i].s << endl;


  i = 0;
  for (; i < second.size() && i < s; ++i)
    cout << "B " << second[i].p << " " << second[i].s << endl;

}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, s;
  while (cin >> n >> s) solve(n , s);
  return 0;
}
