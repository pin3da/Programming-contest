using namespace std;
#include <bits/stdc++.h>

const double eps = 1e-9;
int cmp(double x, double y, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct stop {
  long long left, enter, wait;
  stop() {}
};

int main() {
  long long c, n;
  cin >> c >> n;

  vector<stop> data(n);
  for (int i = 0; i < n; ++i) {
    cin >> data[i].left >> data[i].enter >> data[i].wait;
  }

  if (data[0].left != 0) {
    cout << "impossible" << endl;
    return 0;
  }

  if (data[n - 1].wait != 0) {
    cout << "impossible" << endl;
    return 0;
  }

  long long train = 0;
  for (int i = 0; i < n; ++i) {
    train -= data[i].left;
    if (train < 0) {
      cout << "impossible" << endl;
      return 0;
    }

    train += data[i].enter;
    if (train > c) {
      cout << "impossible" << endl;
      return 0;
    }

    if (c - train > 0 && data[i].wait > 0) {
      cout << "impossible" << endl;
      return 0;
    }
  }

  if (train != 0) {
    cout << "impossible" << endl;
    return 0;
  }

  cout << "possible" << endl;
  return 0;
}
