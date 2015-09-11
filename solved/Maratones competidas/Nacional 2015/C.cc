// EQUIPO TC_BAHIA_01

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

int pos;
const int MN = 6000006;
int ans[MN];
int it;

int parse(const string &a) {
  if (pos < a.size()) {
    if (a[pos] == '(') {
      pos++; // open
      int l = parse(a);
      pos++; // bop
      int r = parse(a);
      pos++; // close );
      ans[it++] = max(l, r) + 1;
      return max(l, r) + 1;
    }
    if (isdigit(a[pos])) {
      while (pos < a.size() && isdigit(a[pos])) {
        pos++;
      }
      ans[it++] = 0;
      return 0;
    }
    pos++; // var;
    ans[it++] = 0;
    return 0;
  }
}

int kmp(const vector<int> &needle, const vector<int> &haystack) {
  int m = needle.size();
  vector<int> border(m);
  border[0] = 0;
  int res = 0;
  for (int i = 1; i < m; ++i) {
    border[i] = border[i - 1];
    while (border[i] > 0 && needle[i] != needle[border[i]]) {
      border[i] = border[border[i] - 1];
    }
    if (needle[i] == needle[border[i]]) border[i]++;
  }
  int n = haystack.size();
  int seen = 0;
  for (int i = 0;i < n; ++i) {
    while (seen > 0 && haystack[i] != needle[seen]) {
      seen = border[seen - 1];
    }
    if (haystack[i] == needle[seen]) seen++;

    if (seen == m) {
      res++;
      seen = border[m - 1];
    }
  }
  return res;
}


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  #ifdef TCBAHIA
  freopen("c.in", "r", stdin);
  #endif // TCBAHIA
  string a, b;
  while (cin >> a >> b) {
    pos = it = 0;
    parse(a);
    vector<int> a1(it);
    for (int i = 0; i < a1.size(); ++i) a1[i] = ans[i];
    pos = it = 0;
    parse(b);
    vector<int> b1(it);
    for (int i = 0; i < b1.size(); ++i) b1[i] = ans[i];
    cout << kmp(a1, b1) << endl;
  }
  return 0;
}
