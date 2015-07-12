using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const double eps = 1e-9;
int cmp(double x, double y, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


int main() {
  map<int, int> sum, carry;
  sum[-1] = 1;
  carry[-1] = 1;
  sum[1] = 1;
  carry[1] = 0;
  sum[2] = 0;
  carry[2] = 1;

  string line;
  while (cin >> line) {
    string ans;
    reverse(line.begin(), line.end());
    int car = 1;
    for (int i = 0; i < line.size(); ++i) {
      if ((i & 1)) {
        car *= -1;
      }
      int cur = line[i] - '0';
      // D(car);
      ans.push_back(sum[cur + car] + '0');
      car = carry[cur+ car];
    }

    if (ans.size() & 1)
      car *= -1;

    if (car) {
      if(carry[car] + sum[car] > 0)
        ans.push_back(sum[car] + '0');
      if (carry[car] > 0)
        ans.push_back(carry[car] + '0');
    }

    reverse(ans.begin(), ans.end());
    int i = 0;
    while(ans[i] == '0' && i < ans.size() - 1) i++;

    cout << ans.substr(i) << endl;
  }

  return 0;
}
