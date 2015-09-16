#include <bits/stdc++.h>
using namespace std;

int bs(int tar, vector<int>& A) { // [F, T] for a[i] > tar
  int lo = -1, hi = A.size();
  while (hi - lo > 1) {
    int mid = (hi + lo) >> 1;
    if (A[mid] <= tar)
      lo = mid;
    else
      hi = mid;
  }
  return hi;
}

int main () {
  string s; cin >> s;
  int q; cin >> q;
  vector<string> ss(q);

  for (int i = 0; i < q; i++)
    cin >> ss[i];

  map<char,vector<int>> A;
  for (int i = 0; i < s.size(); i++)
    A[s[i]].push_back(i);

  int lo, hi;
  for (int k = 0; k < q; k++) {
    bool ok = true;
    int cur = -1;
    for (int i = 0; i < ss[k].size(); i++) {
      char c = ss[k][i];
      int pos = bs(cur, A[c]);
      if (pos == A[c].size() or pos == -1) { // Not found
	ok = false;
	break;
      }
      cur = A[c][pos];
      
      if (i == 0)
	lo = cur;
      if (i + 1 == ss[k].size())
	hi = cur;
    }

    if (!ok)
      cout << "Not matched" << endl;
    else
      cout << "Matched " << lo << " " << hi << endl;
  }
  
  return 0;
}
