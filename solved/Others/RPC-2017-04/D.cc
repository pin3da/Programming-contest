#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << (x) << endl

#define IsComp(n)  (_c[n>>6]&(1<<((n>>1)&31)))
#define SetComp(n) _c[n>>6]|=(1<<((n>>1)&31))
const int MAXP	 = 1000000000;  // sqrt(2^31)
const int SQRP	 = 31623;    // sqrt(MAX)
const int MAX_NP = 60801227;   // 1.26 * MAXP/log(MAXP)
int _c[(MAXP>>6)+1];
int primes[MAX_NP];
int nprimes;
void prime_sieve() {
  for (int i = 3; i <= SQRP; i += 2)
    if (!IsComp(i)) for (int j = i*i; j <= MAXP; j+=i+i) SetComp(j);
  primes[nprimes++] = 2;
  for (int i=3; i <= MAXP; i+=2) if (!IsComp(i)) primes[nprimes++] = i;
}
bool is_prime(int n) {
  if (n < 2 || (n > 2 && n % 2 == 0)) return false;
  return ! IsComp(n);
}


template<class T>
string tos(T t) { stringstream ss; ss << t; string s; ss >> s; return s;}

template<class T>
int toi(T t) { stringstream ss; ss << t; int s; ss >> s; return s;}

bool check(int x) {
  bool ok = true;
  string n = tos(x);
  string r = n;
  int sz = n.size();
  reverse(r.begin(), r.end());
  for (int i = 0; i < sz; i++) {
    string tm = n.substr(i, sz);
    string tr = r.substr(i, sz);
    if (tm[0] == '0' || tr[0] == '0') return false;
    int ntm = toi(tm);
    int ntr = toi(tr);
    if (!is_prime(ntm) || !is_prime(ntr)) return false;
  }
  return true;
}

vector<long long> ans = {2, 3, 5, 7, 37, 73, 313, 347, 353, 373, 383, 743,
  797, 3467, 7643, 34673, 37643, 76367, 79397, 7693967, 799636997};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  /*
  prime_sieve();
    for (int i = 0; i < MAX_NP; ++i) {
      if (check(primes[i])) {
        cout << primes[i] << "\n";
      }
    }
  */

  int tc; cin >> tc;
  while (tc--) {
    long long a, b;
    cin >> a >> b;
    int total = 0;
    for (int i = 0; i < 21; ++i) {
      if (ans[i] >= a && ans[i] <= b)
        total++;
    }
    cout << total << endl;
  }
}
