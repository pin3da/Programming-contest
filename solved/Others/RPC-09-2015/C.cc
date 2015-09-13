#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  while (cin >> n >> m) {
    if (n == m) {
      cout << n << endl;
    } else {
      cout << max(n, m) << endl;
    }
  }
  return 0;
}
