using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'


int kmp(const string &needle) {
  // Precompute border function
  int m = needle.size();
  vector<int> border(m + 1);
  border[0] = -1;
  for (int i = 0; i < m; ++i) {
    border[i+1] = border[i];
    while (border[i+1] > -1 and
           needle[border[i+1]] != needle[i]) {
      border[i+1] = border[border[i+1]];
    }
    border[i+1]++;
  }

  return border.back();
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int k;
  while (cin >> k) {
    if (k == -1) break;
    string line;
    cin >> line;
    int m =  kmp(line);
    k = k - m;
    if (k <= 0)
      cout << 0 << endl;
    else {
      m = line.size() - m;
      cout << k / m << endl;
    }
  }
  return 0;
}
