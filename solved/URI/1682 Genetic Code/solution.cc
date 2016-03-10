#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

string ans;

char a[5000 + 10];
bool compare(int i, int j, int n) {
  for (int k = 0; k < n; ++k) {
    if (a[i] != a[j]) return false;
    i++;j++;
  }
  return true;
}

bool valid(int len) {
  for (int i = 1; i + i <= len; i++) {
    if (compare(len - i - i, len - i, i))
      return false;
  }
  return true;
}

string T = "NOP";
bool gen(int len) {
  if (len == 5005) {
    ans = a;
    return true;
  }
  for (auto &i : T) {
    a[len] = i;
    if (valid(len) && gen(len + 1))
      return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  gen(0);
  int n;
  while (cin >> n && n) {
    cout << ans.substr(0, n) << endl;
  }
  return 0;
}

