#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cout << fixed << setprecision(2);
  while (cin >> n) {
    map<char, int> frec;
    int total = 0;
    for (int i = 0; i < n; ++i) {
      int a; char c;
      cin >> a >> c;
      frec[c] += a;
      total += a;
    }
    cout << "Total: " << total << " cobaias" << endl;

    cout << "Total de coelhos: " << frec['C'] << endl;
    cout << "Total de ratos: " << frec['R'] << endl;
    cout << "Total de sapos: " << frec['S'] << endl;
    cout << "Percentual de coelhos: " << double(frec['C']) * 100.0 / total << " %" << endl;
    cout << "Percentual de ratos: " << double(frec['R']) * 100.0 / total << " %" << endl;
    cout << "Percentual de sapos: " << double(frec['S']) * 100.0 / total << " %" << endl;
  }
  return 0;
}
