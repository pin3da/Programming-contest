// WA ):
#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}
template <typename H, typename... T> void read(vector<H> &h, T&... t) { for (auto &i : h) read(i); read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif


bool is_ok(string &line, int len) {
  vector<int> frec(10);
  for (int i = 0; i < len; i++) {
    frec[line[i] - '0'] ^= 1;
  }

  // first different number
  int first = false;
  int top = int(line[len] - '0') - 1;
  for (int i = top; i >= 1 - (len == 0); i--) {
    if (frec[i]) {
      frec[i] ^= 1;
      first = true;
      break;
    }
  }

  if (!first) {
    debug(top);
    if (top == -1 || (top == 0 && len == 0)) return false;
    frec[top] = 1;
  }

  for (int i = len + 1; i < int(line.size()); i++) {
    int seen = false;
    for (int j = 9; j >= 0; j--) {
      if (frec[j]) {
        frec[j] ^= 1;
        seen = true;
        break;
      }
    }

    if (!seen) {
      frec[9] = 1;
    }
  }
  return accumulate(frec.begin(), frec.end(), 0) == 0;
}

string build(string &line, int len) {
  vector<int> frec(10);
  string ans = line;
  for (int i = 0; i < len; i++) {
    frec[line[i] - '0'] ^= 1;
  }


  int first = false;
  int top = int(line[len] - '0') - 1;
  for (int i = top; i >= 1 - (len == 0); i--) {
    if (frec[i]) {
      frec[i] ^= 1;
      first = true;
      ans[len] = '0' + i;
      break;
    }
  }

  if (!first) {
    frec[top] = 1;
    ans[len] = top + '0';
  }

  for (int i = len + 1; i < int(line.size()); i++) {
    int seen = false;
    for (int j = 9; j >= 0; j--) {
      if (frec[j]) {
        frec[j] ^= 1;
        ans[i] = j + '0';
        seen = true;
        break;
      }
    }

    if (!seen) {
      frec[9] = 1;
      ans[i] = '9';
    }
  }
  return ans;
}

bool is_power(string &line) {
  int ok = line[0] == '1';
  for (int i = 1; i < int(line.size()); i++) {
    ok &= (line[i] == '0');
  }
  return ok;
}

void solve() {
  string line;
  cin >> line;
  int lo = 0, hi = line.size() - 1;

  if (is_power(line)) {
    cout << string(line.size() - 2, '9') << endl;
    return;
  }

  if (is_ok(line, hi)) {
    cout << build(line, hi) << endl;
    return;
  }

  while (lo < hi) {
    int mid = (lo + hi + 1) >> 1;
    if (is_ok(line, mid))
      lo = mid;
    else
      hi = mid - 1;
  }

  debug(lo);

  string ans = build(line, lo);
  if (ans[0] == '0')
    cout << string(line.size() - 2, '9') << endl;
  else
    cout << ans << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  int tc; cin >> tc;
  while (tc--)
    solve();
  return 0;
}

