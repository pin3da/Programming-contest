// http://codeforces.com/contest/479/problem/B

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

const int MN = 111;
int h[MN];
int n;

int finish(){
  int v = h[0];
  for (int i = 0; i < n; ++i)
    if (h[i] != v)
      return false;
  return true;
}

int get_max() {
  int m = 0;
  int k = 0;
  for (int i = 0; i < n; ++i)
    if (h[i] > m) {
      m = h[i];
      k = i;
    }
  return k;
}

int get_min(int j) {
  int m = 10101010;
  int k = 0;
  for (int i = 0; i < n; ++i) {
    if (i == j) continue;
    if (h[i] < m) {
      m = h[i];
      k = i;
    }
  }
  return k;
}




int main() {

  int k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i)
    cin >> h[i];


  vector<int> op;
  while (k and !finish()) {
    int i = get_max();
    int j = get_min(i);
    h[i]--;
    h[j]++;
    op.push_back(i + 1);
    op.push_back(j + 1);
    k--;
  }

  int ans = (*max_element(h, h + n)) - (*min_element(h, h + n));

  cout << ans << " " << op.size() / 2 << endl;
  for (int i = 0; i < op.size(); i += 2)
    cout << op[i] << " " << op[i + 1] << endl;


  return 0;
}