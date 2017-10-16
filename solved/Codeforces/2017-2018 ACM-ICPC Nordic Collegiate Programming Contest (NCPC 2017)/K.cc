#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

struct poss {
  long long val;
  pair<int, int> gen;
  poss() {}
  poss(long long st, int a, int b) : val(st), gen(a, b) {}
  bool operator < (poss &o) const {
    if (val == o.val) return gen < o.gen;
    return val < o.val;
  }
};

bool fun(vector<poss> &comb, vector<long long> &c, vector<long long> frec, long long v) {
  for (int i = 0; i < (int)c.size(); i++) {
    int ok = false;
    for (auto it : comb) {
      if ((it.val * c[i]) >= v) {
        frec[it.gen.first]--;
        frec[it.gen.second]--;

        if (frec[it.gen.second] < 0 || frec[it.gen.first] < 0) {
          frec[it.gen.first]++;
          frec[it.gen.second]++;
          continue;
        }

        ok = true;
        break;
      }
    }
    if (!ok) return false;
  }
  return true;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  vector<long long> frec(3);
  for (int i = 0; i < 3; i++)
    cin >> frec[i];

  vector<long long> str(3);
  for (int i = 0; i < 3; i++)
    cin >> str[i];

  int m = accumulate(frec.begin(), frec.end(), 0) >> 1;
  vector<long long> c(m);
  for (int i = 0; i < m; i++)
    cin >> c[i];

  sort(c.begin(), c.end());
  vector<poss> comb;

  for (int i = 0; i < 3; i++) {
    for (int j = i; j < 3; j++) {
      comb.push_back(poss(str[i] + str[j], i, j));
    }
  }

  sort(comb.begin(), comb.end());

  long long lo = 0, hi = 1e10;
  while (lo < hi) {
    long long mid = (lo + hi + 1) >> 1;
    if (fun(comb, c, frec, mid)) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }

  cout << lo << endl;
  return 0;
}
