using namespace std;
#include <bits/stdc++.h>

const double eps = 1e-9;
int cmp(double x, double y, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    long long n;
    cin >> n;
    deque<int> q;
    while (n > 0) {
      q.push_back(n % 3);
      n /= 3;
    }
    reverse(q.begin(), q.end());
    for (int i = 0; i < q.size(); ++i) {
      if (i) cout << " ";
      cout << q[i];
    }
    cout << endl;
  }
  return 0;
}
