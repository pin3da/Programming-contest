#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    vector<int> a(n), b(n), f_a(11), f_b(11);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    int A = 0, B = 0, c = 0;
    for (int i = 0; i < n; ++i) {
      A += a[i];
      B += b[i];
      if (i) {
        if (a[i] != a[i - 1])
          for (int j = 0; j < 11; ++j) f_a[j] = 0;
        if (b[i] != b[i - 1])
          for (int j = 0; j < 11; ++j) f_b[j] = 0;
      }
      f_a[a[i]]++;
      f_b[b[i]]++;
      if (c || (f_a[a[i]] >= 3 && f_b[b[i]] >= 3)) {c = 1;continue;}

      if (f_a[a[i]] >= 3) {
        c++;
        A += 30;
      }

      if (f_b[b[i]] >= 3) {
        c++;
        B += 30;
      }
    }
    if (A > B)
      cout << 'M' << endl;
    else if (B > A)
      cout << 'L' << endl;
    else
      cout << 'T' << endl;
  }
  return 0;
}
