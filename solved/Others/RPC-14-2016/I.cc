#include<bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl

int main() {
  int n;
  while(cin >> n) {
    long long b = 1;
    while(n){
      b *= 8LL;
      n--;
    }
    cout << b << endl;
  }
  return 0;
}
