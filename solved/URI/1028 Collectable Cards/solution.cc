using namespace std;
#include<bits/stdc++.h>

int main(){
  int n;
  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    while (a != 0 and b != 0) {
      if (a >= b) a %= b;
      else b %= a;
    }
    cout << (a + b) << '\n';
  }
  return 0;
}
