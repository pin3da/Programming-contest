#include <bits/stdc++.h>

using namespace std;
#define debug(x) cout << #x " = " << (x) << endl

const int MN = 505;

int a[MN];
int b[MN];

int erased;
bool join(int b, int e, vector<pair<int, int> > &ans) { // [b, e)

  if (e - b == 1) {
    ans.clear();
    return true;
  }

  int dif = 0;
  for (int i = b; i + 1 < e; ++i) {
    if (a[i] != a[i + 1]) dif++;
  }
  if (dif == 0) return false;

  int id = -1;
  int best = 0;
  set<pair<int, int> > q;
  q.insert(make_pair(b - 1, 1e9));
  q.insert(make_pair(e + 1, 1e9));

  for (int i = b; i < e; ++i) {
    if (a[i] > best) {
      best = a[i];
      id = i;
    }
    q.insert(make_pair(i, a[i]));
  }

  while (q.size() > 3) {
    set<pair<int, int> >::iterator it;
    it = q.lower_bound(make_pair(id, best));
    set<pair<int, int> >::iterator left = it;
    set<pair<int, int> >::iterator right = it;
    left--;
    right++;
    if (left-> second < best) {
      best += left -> second;
      q.erase(left);
      q.erase(it); q.insert(make_pair(id, best));
      // debug(id - erased + 1);
      ans.push_back(make_pair(id - erased + 1, 0));
      erased++;
      continue;
    }
    if (right-> second < best) {
      best += right -> second;
      q.erase(right);
      q.erase(it); q.insert(make_pair(id, best));
      // debug(id - erased + 1);
      ans.push_back(make_pair(id - erased + 1, 1));
      continue;
    }
    return false;
  }
  return true;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  int k; cin >> k;
  for (int i = 0; i < k; ++i) cin >> b[i];

  int ok = true;
  int i = 0, j = 0;
  vector<pair<int, int> > ans;
  erased = 0;
  while (ok && i < n && j < k) {
    int w = i;
    int acc = 0;
    while (w < n && acc < b[j]) {
      acc += a[w];
      w++;
    }
    if (acc > b[j]) {
      // debug("max sum");
      ok = false;
      break;
    }
    vector<pair<int, int> > cur;
    if (join(i, w, cur)) {
      for (int t = 0; t < (int)cur.size(); ++t) {
        ans.push_back(cur[t]);
        if (cur[t].second == 1) erased++;
      }
    } else {
      ok = false;
      // debug("cant join");
      // debug(j);
      break;
    }
    i = w;
    j++;
  }

  if (ok) {
    cout << "YES" << endl;
    for (int i = 0; i < (int) ans.size(); ++i) {
      char t = ans[i].second ? 'R' : 'L';
      cout << ans[i].first << ' ' << t << endl;
    }
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
