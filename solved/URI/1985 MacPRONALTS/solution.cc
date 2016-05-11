#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  map<string, double> p;
  p["1001"] = 1.5;
  p["1002"] = 2.5;
  p["1003"] = 3.5;
  p["1004"] = 4.5;
  p["1005"] = 5.5;

  int n; cin >> n;
  double total = 0;
  while (n--) {
    string a;
    int b;
    cin >> a >> b;
    total += p[a] * b;
  }
  cout << fixed << setprecision(2) << total << endl;

  return 0;
}
