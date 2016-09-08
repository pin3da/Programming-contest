#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int a,c,m,x,q,n;
  while (cin >> a >> c >> m >> x >> q >> n) {
    long long ant = x;
    map<long long, int> pre;
    pre[x]++;

    vector<long long> v;
    v.push_back(x);

    int i = 0;
    int lim = max(n, 1000);
    while ( i < lim) {
      long long other = ((a * ant) + c) % m;
      pre[other] ++;
      if (pre[other] > 2) break;
      v.push_back(other);
      ant = other;
      i++;
    }

    int cycle = 0;
    for (map<long long, int>::iterator i = pre.begin(); i != pre.end(); i++) {
      if (i->second > 1) cycle++;
    }

    int cnt = n / cycle;
    vector<int> good;
    for (int i = 0, j = 0; j < cycle && i < v.size(); ++i) {
      if (pre[v[i]] > 1) {
        pre[v[i]] = cnt;
        good.push_back(v[i]);
        j++;
      }
    }

    int rest = n % cycle;
    for (int i = 0; i < rest && i < good.size(); ++i) {
      pre[good[i]]++;
    }

    for (int j = 0; j < q; ++j) {
      int x;
      cin >> x;
      int found = false;
      int a = 1;
      int b = 1;
      for (map<long long, int>::iterator i = pre.begin(); i != pre.end(); i++) {
        b = a + (i->second - 1);
        if (x >= a && x <= b) {
          cout << i->first << endl;
          found = true;
          break;
        }
        a = b + 1;
      }
    }
  }
  return 0;
}
