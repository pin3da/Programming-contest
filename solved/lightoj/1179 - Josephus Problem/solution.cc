using namespace std;
#include<bits/stdc++.h>

int josephus(int n, int k) {
  if (n == 0) return 1;
  return (josephus(n - 1, k) + k) % n;
}

int solve() {
  int n, k;
  cin >> n >> k;
  cout << josephus(n, k)  + 1 << endl;
}

int main() {

  int n;
  cin >> n;
  for (int i = 0; i < n; ++ i) {
    cout << "Case " << (i + 1) << ": ";
    solve();
  }

  return 0;
}
