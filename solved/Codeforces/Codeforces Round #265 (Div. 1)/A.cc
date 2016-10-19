#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int n, p;

bool fun(string &a, int last) {
  for (int i = last + 1; i < n; ++i) {
    int ok = false;
    for (char c = 'a'; c < p + 'a'; ++c) {
      if ((i - 1 >= 0 && a[i - 1] == c) ||
          (i - 2 >= 0 && a[i - 2] == c))
        continue;

      a[i] = c;
      ok = true;
      break;
    }
    if (!ok) return false;
  }
  return true;
}

bool fix(string &a) {
  for (int i = n - 1; i >= 0; --i) {
    for (char c = a[i] + 1; c < p + 'a'; ++c) {
      if ((i - 1 >= 0 && a[i - 1] == c) ||
          (i - 2 >= 0 && a[i - 2] == c))
        continue;

      a[i] = c;
      return fun(a, i);
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  while (cin >> n >> p) {
    string line;
    cin >> line;
    if (fix(line)) cout << line << endl;
    else cout << "NO" << endl;
  }

  return 0;
}
