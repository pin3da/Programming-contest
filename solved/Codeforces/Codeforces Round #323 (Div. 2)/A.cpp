// http://codeforces.com/contest/583/problem/A

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int n; cin >> n;
  vector<int> col(n, 0), row(n, 0);
  for (int i = 0; i < n * n; ++i) {
    int a, b;
    cin >> a >> b;
    a--;b--;
    if (!col[b] && !row[a]) {
      cout << (i + 1) << " ";
      col[b] = row[a] = 1;
    }
  }
  cout << endl;
  return 0;
}