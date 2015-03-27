using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = " << (x) <<endl
#define endl '\n'

int main() { ___

  int a[2], c;
  while (cin>> a[0] >> a[1] >> c) {
    int t = 0;
    while (c) {
      c -= __gcd(a[t], c);
      t ^= 1;
    }
    cout<< (t ^ 1) << endl;
  }

  return 0;
}