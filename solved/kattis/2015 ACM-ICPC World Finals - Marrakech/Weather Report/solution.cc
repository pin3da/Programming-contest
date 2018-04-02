#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}
template <typename H, typename... T> void read(vector<H> &h, T&... t) { for (auto &i : h) read(i); read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

struct node {
  double prob;
  long long frec;
  double ev;
  node() {}
  node(double p, long long f) : prob(p), frec(f), ev(0) {}
  bool operator < (const node &o) const {
    return prob < o.prob;
  }
};


node merge(node a, node b) {
  node ans;
  ans.frec = 1;
  ans.prob = a.prob + b.prob;
  ans.ev = a.ev + b.ev + ans.prob;
  return ans;
}


void solve() {
  int n;
  cin >> n;
  vector<double> p(4);
  read(p);

  vector<long long> fact(21, 1);
  for (int i = 1; i < 21; i++) {
    fact[i] = fact[i - 1] * i;
  }

  vector<node> all;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= n; k++) {
        if ((i + j + k) > n) continue;
        int m = n - i - j - k;
        long long frec = fact[n] / fact[i] / fact[j] / fact[k] / fact[m];
        double prob = pow(p[0], i) * pow(p[1], j) * pow(p[2], k) * pow(p[3], m);
        all.emplace_back(prob, frec);
      }
    }
  }

  multiset<node> pq(all.begin(), all.end());

  while (pq.size() > 1) {
    node cur = *pq.begin();
    pq.erase(pq.begin());
    if (cur.frec & 1) {
      cur.frec--;

      node cur2 = *pq.begin();
      pq.erase(pq.begin());
      cur2.frec--;
      if (cur2.frec) pq.insert(cur2);

      node nxt = merge(cur, cur2);
      pq.insert(nxt);
    }
    if (cur.frec > 1) {
      node nxt;
      nxt.prob = cur.prob * 2;
      nxt.frec = cur.frec / 2;
      nxt.ev = 2 * (cur.prob + cur.ev);
      pq.insert(nxt);
    }
  }

  assert(pq.size() == 1);
  cout << fixed << setprecision(7);
  cout << pq.begin()->ev << endl;

}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  solve();
  return 0;
}

