#include <bits/stdc++.h>

using namespace std;
#define debug(x) cout << #x " = " << (x) << endl

struct pp {
  long long a, b, c;
  int id;
  pp() {}
  pp(long long x, long long y, long long z, int i) :
    a(x), b(y), c(z), id(i) {}

  long long fun() {
    return min(min(a, b), c);
  }
};

const int MN = 1e5 + 100;

pp a[MN];
typedef map<pair<int, int>, vector<pair<int, int> > > tree;
tree ds;

pair<int, int> mp(long long a, long long b) {
  return make_pair(min(a, b), max(a, b));
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n; cin >> n;
  long long best = -1;
  int id = -1, id2 = -1;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].a >> a[i].b >> a[i].c;
    a[i].id = i;

    ds[mp(a[i].a, a[i].b)].push_back(make_pair(a[i].c, i));
    ds[mp(a[i].a, a[i].c)].push_back(make_pair(a[i].b, i));
    ds[mp(a[i].c, a[i].b)].push_back(make_pair(a[i].a, i));

    if (a[i].fun() > best) {
      best = a[i].fun();
      id = i;
    }

  }
  for (tree::iterator it = ds.begin(); it != ds.end(); ++it) {
    if (it-> second.size() > 1) {
      sort(it->second.rbegin(), it-> second.rend());
      long long x = it-> first.first, y = it-> first.second;
      long long z = it-> second[0].first + it-> second[1].first;
      long long val = min(min(x, y), z);
      if (val > best) {
        best = val;
        id = it-> second[0].second;
        id2 = it-> second[1].second;
      }
    }
  }
  if (id2 != -1) {
    cout << 2 <<  endl;
    cout << id + 1 << ' ' << id2 + 1 << endl;
  } else {
    cout << 1 << endl;
    cout << id + 1 << endl;
  }

  return 0;
}
