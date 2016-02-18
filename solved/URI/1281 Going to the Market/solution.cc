#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    int p;
    cin >> p;
    unordered_map<string, double> price;
    string name;
    double pri;
    for (int i = 0; i < p; ++i) {
      cin >> name >> pri;
      price[name] = pri;
    }
    cin >> p;
    double total = 0;
    for (int i = 0; i < p; ++i) {
      cin >> name >> pri;
      total += price[name] * pri;
    }
    cout << "R$ " << fixed << setprecision(2) << total << endl;
  }
  return 0;
}

