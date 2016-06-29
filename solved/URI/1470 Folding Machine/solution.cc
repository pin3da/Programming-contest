#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

void D(vector<int> a) {
  for (auto &i : a) cout << i << ' ';
  cout << endl;
}

vector<int> gen_next(const vector<int> &a, int i) {
  int l = i + 1;
  int r = a.size() - l;
  vector<int> next(max(r, l));
  if (l >= r) {
    int k = i;
    for (int j = i + 1; j < a.size(); ++j, --k) {
      next[k] += a[k];
      next[k] += a[j];
    }
    while (k >= 0) {
      next[k] += a[k];
      k--;
    }
  } else {
    int k = 0;
    for (int j = i; j >= 0; --j, ++k) {
      next[i - j] += a[j];
      next[k] += a[i + k + 1];
    }
    while (k + i + 1 < a.size()) {
      next[k] += a[i + k + 1];
      k++;
    }
    reverse(next.begin(), next.end());
  }
  return next;
}


set<vector<int>> seen;
bool bf(vector<int> a, vector<int> &b) {
  if (seen.count(a)) return false;
  if (a.size() < b.size()) return false;
  if (a == b) return true;

  seen.insert(a);
  for (int i = 0; i + 1 < a.size(); ++i) {
    vector<int> next = gen_next(a, i);
    if (bf(next, b))
      return true;
  }
  reverse(a.begin(), a.end());
  if (bf(a, b))
    return true;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int n;
  while (cin >> n) {
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    int m; cin >> m;
    vector<int> b(m);
    for (auto &i : b) cin >> i;

    if (bf(a, b))
      cout << "S" << endl;
    else
      cout << "N" << endl;
  }
  return 0;
}
