#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout <<#x " = " << x << endl

using namespace std;

bool valid(vector<int> &a) {
  for (int i = 1; i - 1 < a.size(); ++i) {
    for (int j = i + i; j - 1 < a.size(); j += i) {
      if ((a[i - 1] % i) != (a[j - 1] % i)) return false;
    }
  }
  return true;
}

vector<vector<int> > all;
void  gen(vector<int> a) {
  if (a.size() == 8) {
    if (valid(a)) all.push_back(a);
    return;
  }

  for (int i = 0; i <= a.size(); ++i) {
    vector<int> nxt = a;
    nxt.push_back(i);
    gen(nxt);
  }
}


const long long mod = 1e9 + 7;
long long bf(vector<int> &a, int i) {
  if (i == a.size()) {
    if (valid(a)) {
      for (int j = 0; j < a.size(); ++j)
        cout << a[j] << ' ';
      cout << endl;
      return 1;
    }
    return 0;
  }

  long long ans = 0;
  if (a[i] == -1) {
    for (int j = 0; j <= i; ++j) {
      a[i] = j;
      ans += bf(a, i + 1);
      ans %= mod;
    }
    a[i] = -1;
  } else {
    ans = bf(a, i + 1);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  cout << bf(a, 0) % mod << endl;
  return 0;
}
