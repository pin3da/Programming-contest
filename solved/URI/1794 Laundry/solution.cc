#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

bool check(int n, int a, int b) {
  for (int i = a; i <= b; ++i) {
    if (n == i) return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    int la, lb, sa, sb;
    cin >> la >> lb >> sa >> sb;
    if (check(n, la, lb) && check(n, sa, sb))
      cout << "possivel" << endl;
    else
      cout << "impossivel" << endl;
  }
  return 0;
}
