// http://codeforces.com/contest/480/problem/B

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

typedef long long lint;


int main() { ___

  lint n, l, x, y;
  cin >> n >> l >> x >> y;

  vector<lint> marks(n);
  for (int i = 0; i < n; ++i)
    cin >> marks[i];

  int seenx = 0, seeny = 0;
  vector<int> possiblex, possibley;
  for (int i = 0; i < n; ++i) {
    lint need = marks[i] + x;
    if(binary_search(marks.begin(), marks.end(), need))
        seenx = true;
    else {
      if (need < l)
        possiblex.push_back(need);
      if (marks[i] - x > 0)
        possiblex.push_back(marks[i] - x);
    }

    need = marks[i] + y;
    if(binary_search(marks.begin(), marks.end(), need))
        seeny = true;
    else {
      if (need < l)
        possibley.push_back(need);
      if (marks[i] - y > 0)
        possibley.push_back(marks[i] - y);
    }
  }

  if (seenx and seeny) {
    cout << 0 << endl;
    return 0;
  }

  if (seenx) {
    cout << 1 << endl << possibley[0] << endl;
    return 0;
  }

  if (seeny) {
    cout << 1 << endl << possiblex[0] << endl;
    return 0;
  }

  /*for (int i = 0; i < possiblex.size(); ++i)
    cout << possiblex[i] << " ";
  cout << endl;

  for (int i = 0; i < possibley.size(); ++i)
    cout << possibley[i] << " ";

  cout << endl;*/
  sort(possibley.begin(), possibley.end());
  sort(possiblex.begin(), possiblex.end());

  for (int i = 0; i < possiblex.size(); ++i) {
    if (binary_search(possibley.begin(), possibley.end(), possiblex[i])) {
      cout << 1 << endl << possiblex[i] << endl;
      return 0;
    }
  }

  cout << 2 << endl << possiblex[0] << " " << possibley[0] << endl;


  return 0;
}