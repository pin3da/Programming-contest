using namespace std;
#include <bits/stdc++.h>
#define endl '\n'

int mod = 360000;

// Reports all occurrences of 'needle' in 'haystack'.
int kmp(const vector<int> &needle, const vector<int> &haystack) {
  // Precompute border function
  int m = needle.size();
  vector<int> border(m + 1);
  border[0] = -1;
  for (int i = 0; i < m; ++i) {
    border[i+1] = border[i];
    while (border[i+1] > -1 and
           needle[border[i+1]] != needle[i]) {
      border[i+1] = border[border[i+1]];
    }
    border[i+1]++;
  }

  // Now the actual matching
  int n = haystack.size();
  int seen = 0;
  for (int i = 0; i < n; ++i){
    while (seen > -1 and needle[seen] != haystack[i]) {
      seen = border[seen];
    }
    if (++seen == m) {
      //printf("Needle occurs from %d to %d\n", i - m + 1, i);
      return true;
      seen = border[m];
    }
  }

  return false;
}

int possible(vector<int> a, vector<int> b) {
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int n = a.size();

  vector<int> da(n + n), db(n);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    da[i + n] = da[i] = (a[(i + 1) % n] - a[i] + mod) % mod;
    db[i] = (b[(i + 1) % n] - b[i] + mod) % mod;
  }

  return kmp(db, da);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  for (int i = 0; i < n; ++i)
    cin >> b[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int ans = possible(a, b);

  if (ans) {
    cout << "possible" << endl;
    return 0;
  }

  if (a[0] == 0) {
    a[0] = mod;
    if (possible(a, b)) {
      cout << "possible"  << endl;
      return 0;
    }
    a[0] = 0;
  }

  if (b[0] == 0) {
    b[0] = mod;
    if (possible(a, b)) {
      cout << "possible"  << endl;
      return 0;
    }
    b[0] = 0;
  }

  cout << "impossible" << endl;
  return 0;
}
