#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  map<int, int> f;
  int t;
  while (n--) {
    cin >> t;
    f[t]++;
  }

  for (auto &i : f) {
    cout << i.first << " aparece " << i.second << " vez(es)" << endl;
  }
  return 0;
}

