#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  srand(time(0));
  int n = 10000;
  for (int i = 0; i < n; ++i) {
    cout << char(random() % 26 + 'a');
  }
  cout << endl;
  return 0;
}
