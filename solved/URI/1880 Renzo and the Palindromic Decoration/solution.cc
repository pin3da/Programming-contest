#include<bits/stdc++.h>
using namespace std;

char conv(int x) {
  if( x < 10) return char('0' + x);
  return char('A' + (x - 10));
}

bool ch_base(int x, int b) {
  string s, t;
  while(x) {
    int r = x % b;
    s.push_back(conv(r));
    x /= b;
  }
  t = s;
  reverse(t.begin(), t.end());
  return t == s;
}

int main() {
  int n, t; cin >> t;
  while(t--) {
    cin >> n;
    bool first = false;
    for(int i = 2; i < 17; i++) {
      if(ch_base(n, i)){
        if(first) cout << " ";
        cout << i;
        first = true;
      }
    }
    if(!first) cout << -1;
    cout << endl;
  }
  return 0;
}
