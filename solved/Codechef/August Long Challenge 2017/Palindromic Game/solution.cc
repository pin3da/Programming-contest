#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl


string insert(string w, int pos, char v) {
  string pref = w.substr(0, pos);
  string suff = w.substr(pos);
  return pref + v + suff;
}

string remove(string w, int pos) {
  string pref = w.substr(0, pos);
  string suff = w.substr(pos + 1);
  return pref + suff;
}

bool is_pal(string w) {
  if (w.size() <= 1) return false;
  int n = w.size() / 2;
  for (int i = 0; i < n; i++) {
    if (w[i] != w[w.size() - i - 1])
      return false;
  }
  return true;
}

bool win(string s, string t, string w, int p, int dep=0) {
  if (dep > 2) return false;
  if (p == 0) {
    for (int i = 0; i < (int) s.size(); i++) {
      for (int j = 0; j <= (int) w.size(); j++) {
        string next = insert(w, j, s[i]);
        if (is_pal(next)) {
          return true;
        }
        if (win(remove(s, i), t, next, p ^ 1, dep+1))
          return true;
      }
    }
    return false;
  } else {
    for (int i = 0; i < (int) t.size(); i++) {
      for (int j = 0; j <= (int) w.size(); j++) {
        string next = insert(w, j, t[i]);
        if (is_pal(next)) {
          return false;
        }
        if (!win(s, remove(t, i), next, p ^ 1, dep+1))
          return false;
      }
    }
    if (t.size() == 0) return false;
    return true;
  }
}

vector<int> get_frec(string &s) {
  vector<int> frec(30);
  for (auto c: s) frec[c - 'a']++;
  return frec;
}

string compress(string s) {
  vector<int> f_s = get_frec(s);
  s = "";
  for (int i = 0; i < (int) f_s.size(); i++)
    for (int j = 0; j < min(f_s[i], 2); j++)
      s.push_back(i + 'a');
  return s;
}

void solve() {
  string s, t;
  cin >> s >> t;
  s = compress(s);
  t = compress(t);
  vector<int> frec_t = get_frec(t);
  int all = true;
  for (auto i : s)
    all &= (frec_t[i - 'a'] > 0);
  if (all) {
    puts("B");
    return;
  }
  int w = win(s, t, "", 0);
  puts(w ? "A" : "B");
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  assert(insert("abc", 0, 'x') == "xabc");
  assert(insert("abc", 3, 'x') == "abcx");
  assert(insert("abc", 1, 'x') == "axbc");
  assert(remove("abc", 1) == "ac");
  int tc; cin >> tc;
  while (tc--) solve();
  return 0;
}
