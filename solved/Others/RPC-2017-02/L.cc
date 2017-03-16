using namespace std;
#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << (x) << endl

bool check_masks(int a, int b) {
  for (int i = 0; i < 32; i++) {
    if ( (a & (1 << i)) != 0 && (b & (1 << i)) != 0) return false;
  }
  return true;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<long long> marbells(n), plates(m);
  set<long long> ans;

  for (int i = 0; i < n; i++) {
    cin >> marbells[i];
    ans.insert(marbells[i]);
  }
  for (int i = 0; i < m; i++) cin >> plates[i];

  vector<pair<long long, int> > masks;
  for (int i = 1; i < (1 << m); i++) {
    long long sum = 0;
    for (int j = 0; j <  m; j++) {
      if ((i & (1 << j)) != 0) {
        sum += plates[j];
      }
    }
    masks.push_back(make_pair(sum, i));
  }

  sort(masks.begin(), masks.end());
  int ms = masks.size();
  for (int i = 0;  i < ms; i++) {
    int j = i;
    long long sum = masks[i].first;
    bool ok = false;
    while (j + 1 < ms && masks[j + 1].first == masks[i].first) {
      if (check_masks(masks[j + 1].second, masks[i].second)) {
        ok = true;
      }
      j++;
    }
    if (ok) {
      i = j;
      for (int j = 0; j < n; j++) {
        ans.insert(marbells[j] + sum * 2);
      }
    }
  }
  for (auto i : ans)
    cout << i << endl;
  return 0;
}
