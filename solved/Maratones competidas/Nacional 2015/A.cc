using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

string next_pal(string s) {
  int carry = 1;
  for (int i = 0, j = s.size() - 1; i < s.size(); ++i, --j) {
    if (i < j) {
      if (carry) {
        if (s[i] > s[j]) {
          s[j] = s[i];
          carry = 0;
        } else {
          s[j] = s[i];
        }
      } else {
        if (s[i] < s[j]) {
          s[j] = s[i];
          carry = 1;
        } else {
          s[j] = s[i];
        }
      }
    } else {
      if (carry) {
        if (s[j] == '9') {
          s[j] = '0';
          s[i] = '0';
        } else {
          s[j]++;
          s[i] = s[j];
          carry = 0;
        }
      }
    }
  }
  if (carry) {
    s[s.size() - 1] = '1';
    s = "1" + s;
  }
  return s;
}

int main() {
  int n; string l;
  while (cin >> n >> l) {
    while (n--) {
      l = next_pal(l);
      cout << l << endl;
    }
  }

  return 0;
}
