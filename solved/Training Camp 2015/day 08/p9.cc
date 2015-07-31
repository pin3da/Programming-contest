using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int a, b, c;
  while ( cin >> a >> b >> c) {
    int g = __gcd(a * b, c - b);
    cout << (a *  b) / g << "/" << (c - b) / g<< endl;
  }

  return 0;
}
