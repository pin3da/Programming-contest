#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}
template <typename H, typename... T> void read(vector<H> &h, T&... t) { for (auto &i : h) read(i); read(t...) ;}

#ifndef LOCAL
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif


void solve() {
  int grumpy = false;
  int no = 0;
  for (int i = 0; i < 10; i++) {
    cout << i << endl;
    string ans; getline(cin, ans);
    if (ans == "no" && no == 3) {
      break;
    }
    if (ans == "no") no++;
    else if (ans == "don't even" || ans == "are you serious?" || ans == "no way" ||
            ans == "terrible" || ans == "worse" || ans == "go die in a hole") {
      grumpy = true;
      break;
    } else {
      break;
    }
  }
  if (grumpy)
    cout << "grumpy" << endl;
  else
    cout << "normal" << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  //int tc; cin >> tc;
  //while (tc--)
    solve();
  return 0;
}

