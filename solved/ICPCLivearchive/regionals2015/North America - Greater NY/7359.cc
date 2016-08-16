#include <bits/stdc++.h>
#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl

using namespace std;

const int MN = 30000;
int a[MN], b[MN], c[MN];

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int j = 1, k = 1;
  for (int i = 1; i < MN; ++i) {
    a[i] = a[i - 1] + i;
    if (i & 1) {
      b[j] = b[j - 1] + i;
      j++;
    } else {
      c[k] = c[k - 1] + i;
      k++;
    }
  }
  int p; cin >> p;
  while (p--) {
    int id, n;
    cin >> id >> n;
    cout << id << " " << a[n] << ' ' << b[n] << ' ' << c[n] << endl;
  }

  return 0;
}
