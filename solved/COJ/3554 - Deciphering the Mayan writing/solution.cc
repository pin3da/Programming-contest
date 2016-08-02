#include<bits/stdc++.h>
#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl

using namespace std;


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int a, b;
  while(cin >> a >> b) {
    string x, y;
    cin >> x >> y;

    map<char, int> frec, cur;
    for (char i = 'a'; i <= 'z'; ++i) {
      frec[i] = cur[i] = 0;
    }
    for (char i = 'A'; i <= 'Z'; ++i) {
      frec[i] = cur[i] = 0;
    }
    int ans = 0;

    for (auto &i: x) frec[i]++;

    if (y.size() < x.size()) {
      cout << 0 << endl;
      continue;
    }


    for (int i = 0; i < x.size(); ++i) {
      cur[y[i]]++;
    }

    if (cur == frec) ans++;
    for (int i = x.size(); i < y.size(); ++i) {
      cur[y[i]]++;
      cur[y[i - x.size()]]--;
      if (cur == frec) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
