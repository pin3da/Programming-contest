#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, k, t, c;
  while (cin >> n >> k) {
    long long ans = 0;
    deque<pair<int, long long > > neg, pos;
    for (int i = 0; i < n; i++) {
      cin >> t >> c;
      if (t > 0) pos.push_back(make_pair(t, c));
      if (t < 0) neg.push_back(make_pair(-t, c));
    }
    sort(pos.rbegin(), pos.rend());
    sort(neg.rbegin(), neg.rend());
    
    while (!neg.empty()) {
      pair<int, long long > top = neg.front(); neg.pop_front();
      //cout << top.first << endl;
      long long trips = top.second /  k;
      int mod = (top.second % k);
      trips += (mod != 0);
      int res = 0;
      if (mod)
        res = k - mod;
      //cout << top.first  << " " << trips << " " << res<< endl;
      ans += trips * top.first * 2;
      if (!neg.empty() && res) {
        while (!neg.empty() && res > 0) {
          top = neg.front();
          neg.pop_front();
          if (res >= top.second) {  
            res -= top.second;
          }else {
            top.second -= res;
            neg.push_front(top);
            res = 0;
          }
        }
      }
    }
    //cout << "sale"<< endl;
    while (!pos.empty()) {
      pair<int, long long > top = pos.front(); pos.pop_front();
      long long trips = top.second /  k;
      int mod = (top.second % k);
      trips += (mod != 0);
      int res = 0;
      if (mod)
        res = k - mod;
      ans += trips * top.first * 2;
      if (!pos.empty() && res) {
        while (!pos.empty() && res > 0) {
          top = pos.front();
          pos.pop_front();
          if (res >= top.second) {  
            res -= top.second;
          }else {
            top.second -= res;
            pos.push_front(top);
            res = 0;
          }
        }
      }
    }
    cout << ans << endl;
  }
}

