using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

long long fact[20];

long long recover(vector<int> &a, int tk, int ft) {
  long long ans = 0;
  for (int i = 0; i < a.size(); ++i) {
    if ((tk >> i) & 1) {
      if ((ft >> i) & 1)
        ans += fact[a[i]];
      else
        ans += a[i];
    }
  }
  return ans;
}

unordered_set<long long> seen[2];
void fun(int index, vector<int> &a, int i, int k, int taken, int ft, vector<long long> &res, long long &s) {
  if (k < 0)
    return;
  if (recover(a, taken, ft) > s)
    return;
  if (i == a.size()) {
    if (seen[index].count(taken << 15 | ft) == 0) {
      res.push_back(recover(a, taken, ft));
      seen[index].insert(taken << 15 | ft);
    }
    return;
  }

  fun(index, a, i + 1, k, taken, ft, res, s);
  fun(index, a, i + 1, k - 1, taken | (1 << i), ft, res, s);
  if (a[i] < 20)
    fun(index, a, i + 1, k - 1,taken | (1 << i), ft | (1 << i) , res, s);
}

typedef vector<long long>::reverse_iterator vrit;
typedef vector<long long>::iterator vit;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  fact[0] = 1;
  for (int i = 1; i < 20; ++i) {
    fact[i] = fact[i - 1] * (long long) (i);
  }
  int n, k;
  long long s;
  while (cin >> n >> k >> s) {
    seen[0].clear();
    seen[1].clear();
    vector<int> a, b;
    int t;
    for (int i = 0; i < n; ++i) {
      cin >> t;
      if (i < (n / 2))
        a.push_back(t);
      else
        b.push_back(t);
    }

    long long ans = 0;
    vector<long long> s1, s2;
    for (int i = 0; i <= k; ++i) {
      fun(0, a, 0, i, 0, 0, s1, s);
      fun(1, b, 0, k - i, 0, 0, s2, s);
    }

    /*
     *unordered_map<long long, int> frec(s2.size());
     *for (int j = 0; j < s2.size(); ++j) {
     *  frec[s2[j]]++;
     *}
     *long long tmp = 0;
     * tmp += count(s1.begin(), s1.end(), s) + frec[s];
     *for (int i = 0; i < s1.size(); i++) {
     *  if (frec.count(s - s1[i]))
     *    tmp += frec[s - s1[i]];
     *}
     * D(tmp);
     *ans += tmp;
     */

    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());

    vit i=s1.begin();
    vrit j=s2.rbegin();
    while ( (i!=s1.end()) && (j!=s2.rend()) ) {
      if ( (j==s2.rend()) || ((*i + *j) < s) ) ++i;
      else if ( (i==s1.end()) || ((*i + *j) > s) ) ++j;
      else {
        //none has ended and sum is just what we need
        vit ii=i+1;
        vrit jj=j+1;
        while ( (ii!=s1.end()) && (*ii == *i) ) ++ii;
        while ( (jj!=s2.rend()) && (*jj == *j) ) ++jj;
        ans += (ii-i)*(jj-j);
        i=ii; j=jj;
      }
    }

    cout << ans << endl;
  }
  return 0;
}

