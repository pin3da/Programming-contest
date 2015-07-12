using namespace std;
#include <bits/stdc++.h>

const double eps = 1e-9;
int cmp(double x, double y, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


int main() {
  int a, b, c, d;
  int e, f, g, h;

  cin >> a >> b >> c >> d;
  cin >> e >> f >> g >> h;

  vector<int> val_a, val_b;
  for (int i = a; i <= b; ++i) {
    for (int j = c; j <= d; ++j) {
      val_a.push_back(i + j);
    }
  }

  for (int i = e; i <= f; ++i) {
    for (int j = g; j <= h; ++j) {
      val_b.push_back(i + j);
    }
  }

  double ev_a = 1.0 / ((b - a + 1) * (d - c + 1));
  double ev_b = 1.0 / ((f - e + 1) * (h - g + 1));

  double prob_a = 0, prob_b = 0, tie = 0;
  for (int i = 0; i < val_a.size(); ++i) {
    for (int j = 0; j < val_b.size(); ++j) {
      if (val_a[i] < val_b[j]) {
        prob_a += ev_a * ev_b;
      }
      else if (val_b[j] < val_a[i]) {
        prob_b += ev_a * ev_b;
      }
      else {
        tie += ev_a * ev_b;
      }
    }
  }

  if (cmp(prob_a, prob_b) == 1) {
    cout << "Emma" << endl;
  }
  else if (cmp(prob_a, prob_b) == -1) {
    cout << "Gunnar" << endl;
  }
  else {
    cout << "Tie" << endl;
  }
  // cout << prob_a << " " << prob_b << " " << tie << endl;
  // cout << prob_a + prob_b + tie << endl;
  return 0;
}
