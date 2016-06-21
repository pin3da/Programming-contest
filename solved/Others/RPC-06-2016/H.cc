#include <bits/stdc++.h>
#define endl '\n'
#define debug(x) cout << #x  " = " << (x) << endl

using namespace std;

pair<int, int> left(vector<int> &a, int s) {
  if (a.size() == 0) return make_pair(0, s);
  int total = 0;
  for (int i = 0; i < a.size(); i += 5)
    total += 2 * (s - a[i]);
  return make_pair(total, a[0]);
}

pair<int, int> right(vector<int> &a, int s) {
  if (a.size() == 0) return make_pair(0, s);
  int total = 0;
  for (int i = 0; i < a.size(); i += 5)
    total += 2 * (a[i] - s);
  return make_pair(total, a[0]);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    vector<int> h(n);
    for (auto &i : h) cin >> i;
    int start; cin >> start;
    sort(h.begin(), h.end());
    vector<int> l, r;
    for (auto &i : h)
      if (i < start)
        l.emplace_back(i);
      else if (i > start)
        r.emplace_back(i);

    sort(r.rbegin(), r.rend());
    pair<int, int> ll = left(l, start);
    pair<int, int> rr = right(r, start);
    int ans = n + ll.first + rr.first;
    int best = start - ll.second;
    best = max(best, rr.second - start);
    cout << ans - best << endl;
  }
  return 0;
}
