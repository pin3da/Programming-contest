using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

typedef unsigned long long H;

const int MN = 40004;
const H pi = 21613;
H p[MN];

H compute(string s) {
  H h = 0;
  for (int i = 0; i < s.size(); ++i) {
    h += p[i] * (s[i] - 'a' + 1);
  }
  return h;
}

bool possible(const string &s, int k, int m, int &ll) {
  vector<pair<H, int>> frec;
  H cur = 0;

  int l = s.size() - 1;
  for (int i = 0; i < k; ++i) {
    cur += p[l - i] * (s[i] - 'a' + 1);
  }

  frec.push_back(make_pair(cur, k - 1));

  for (int i = k; i < s.size(); ++i) {
    cur -=  p[l - (i - k)] * (s[i - k] - 'a' + 1);
    cur +=  p[l - i] * (s[i] - 'a' + 1);
    H cur2 = cur * p[i - k + 1];
    frec.push_back(make_pair(cur2, i));
  }

  sort(frec.begin(), frec.end());
  int oc = 1, last = 0;
  bool seen = false;
  for (int i = 1; i < frec.size(); ++i) {
    if (frec[i].first == frec[i - 1].first) {
      oc++;
    } else {
      oc = 1;
    }
    if (oc >= m) {
      last = max(last, frec[i].second);
      seen = true;
    }
  }

  if (oc >= m) {
    last = max(last, frec.back().second);
    seen = true;
  }

  ll = last;
  return seen;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  int m;
  p[0] = 1;
  for (int i = 1; i < MN; ++i) {
    p[i] = p[i - 1] * pi;
  }

  while (cin >> m && m) {
    cin >> line;
    if (m == 1) {
      cout << line.size() << " " << 0 << endl;
      continue;
    }

    int last = 0;
    if (!possible(line, 1, m, last)) {
      cout << "none" << endl;
      continue;
    }
    int lo = 1, hi = line.size() - 1;
    while (lo < hi) {
      if (lo + 1 == hi) {
        if (possible(line, hi, m, last))
          lo = hi;
        break;
      }
      int mid = (lo + hi) >> 1;
      if (possible(line, mid, m, last)) {
        lo = mid;
      } else {
        hi = mid - 1;
      }
    }

    possible(line, lo, m, last);
    cout << lo << " " << last - lo + 1 << endl;
  }
  return 0;
}
