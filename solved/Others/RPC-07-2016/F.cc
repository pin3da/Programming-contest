#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long total, s, m, d, b;

  while (cin >> total >> s >> m >> d >> b && (total + s + m + d + b)) {
    map<long long, long long> r, l;
    vector<long long> first(s);
    for (auto &i : first) cin >> i;

    long long tmp;
    for (int i = 0; i < m; ++i) {
      cin >> tmp;
      for (auto &j: first) {
        r[tmp + j]++;
      }
    }

    first.resize(d);
    for (auto &i : first) cin >> i;
    for (int i = 0; i < b; ++i) {
      cin >> tmp;
      for (auto &j: first) {
        l[tmp + j]++;
      }
    }

    vector<long long> ans_acc(r.size());
    vector<long long> ans_id(r.size());
    int j = 0;
    for (auto &i : r) {
      ans_id[j] = i.first;
      ans_acc[j] = i.second;
      if (j)
        ans_acc[j] += ans_acc[j - 1];
      j++;
    }

    long long ans = 0;
    for (auto &i : l) {
      long long mm = total - i.first;
      if (mm <= 0) continue;
      int lo = 0, hi = ans_id.size() - 1;
      while (lo < hi) {
        int mid = (lo + hi + 1) >> 1;
        if (ans_id[mid] <= mm) {
          lo = mid;
        } else {
          hi = mid - 1;
        }
      }
      if (ans_id[lo] > mm) continue;
      ans += i.second * ans_acc[lo];
    }
    cout << ans << endl;
  }

  return 0;
}
