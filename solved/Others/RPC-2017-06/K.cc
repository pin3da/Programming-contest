#include <bits/stdc++.h>
#define SQ(X) ((X) * (X))

using namespace std;

typedef pair<char, double> ii;

int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector< ii > input(n);
    for (int i = 0; i < n; i++) {
      char c; cin >> c;
      int k; cin >> k;
      input[i] = ii(c, k);
    }
    int i = 1;
    double width = input[0].second;
    while (true) {
      width += input[i].second;
      if (input[i].first == 'C') break;
      i++;
    }
    double height = input[i++].second;
    while (true) {
      height += input[i].second;
      if (input[i].first == 'C') break;
      i++;
    }
    double area = 0.0;
    for (i = 0; i < n; i++) {
      if (input[i].first == 'T')
        area += (input[i].second * sqrt(SQ(input[i].second) - SQ(input[i].second * 0.5))) * 0.5;
      else
        area += SQ(input[i].second);
    }
    double ans = width * height - area;
    cout << fixed << setprecision(4) << ans << endl;
  }
  return 0;
}
