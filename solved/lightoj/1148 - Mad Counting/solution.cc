using namespace std;
#include<bits/stdc++.h>

const int MN = 1000001;

void solve() {
  int n;
  cin >> n;
  vector<int> frec(MN, 0);
  long long ans = 0;
  int t;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    frec[t]++;
    if (frec[t] == t + 1) {
      ans+= t + 1;
      frec[t] = 0;
    }
  }

  for (int i = 0; i < MN; ++i)
    if (frec[i] != 0)
      ans+= i + 1;

  cout << ans << endl;
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n + 1; ++i) {
    cout << "Case "  << i << ": ";
    solve();
  }

  return 0;
}
