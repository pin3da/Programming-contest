#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

const string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";

const string pref = "What are you doing while sending \"";
const string mid = "\"? Are you busy? Will you send \"";
const string suf = "\"?";

const long long MX = 1e18;

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  vector<long long> len;

  len.push_back(f0.size());

  for (int i = 1; i < 53; i++) {
    len.push_back(pref.size() + len[i - 1] + mid.size() + len[i - 1] + suf.size());
  }

  int q;
  cin >> q;
  while (q--) {
    long long n, k;
    cin >> n >> k;
    k--;
    int found = false;

    while (n > (long long)len.size() && !found) {
      if (k < (long long)pref.size()) {
        cout << pref[k];
        found = true; continue;
      } else {
        n--;
        k -= pref.size();
      }
    }

    while (n > 0 && !found) {
      if (k < (long long)pref.size()) {
        cout << pref[k];
        found = true; continue;
      }

      k -= pref.size();
      if (k < len[n - 1]) {
        n--; continue;
      }

      k -= len[n - 1];

      if (k < (long long)mid.size()) {
        cout << mid[k];
        found = true; continue;
      }

      k -= mid.size();

      if (k < len[n - 1]) {
        n--; continue;
      }

      k -= len[n - 1];

      if (k < (long long)suf.size()) {
        cout << suf[k];
        found = true; continue;
      } else {
        cout << '.';
        found = true; continue;
      }
    }

    if (!found) {
      if (k < (long long)f0.size())
        cout << f0[k];
      else
        cout << '.';
    }
  }
  cout << endl;
  return 0;
}
