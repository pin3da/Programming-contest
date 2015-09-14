#include <bits/stdc++.h>
using namespace std;

const int MN = 70000;
vector<int> primes;

void prime_sieve() {
  vector<bool> p(MN, true);
  p[1] = false;
  for (int i = 2; i * i <= MN; i++) {
    if (!p[i])
      continue;

    // cout << i << " ";
    primes.push_back(i);
    for (int j = i * i; j <= MN; j += i)
      p[j] = false;
  }

  for (int i = 2; i < MN; i++) {
    if (p[i])
      primes.push_back(i);
  }
  // cout << endl;
}

vector<int> factor(int n) {
  vector<int> pf;
  for (int i = 0; i < primes.size() and primes[i] * primes[i] <= n; i++) {
    while (n % primes[i] == 0) {
      pf.push_back(primes[i]);
      n /= primes[i];
    }
  }
  if (n != 1)
    pf.push_back(n);
  return pf;
}

int main() {
  prime_sieve();
  int n;
  while (cin >> n and n) {
    if (n % 2 == 0) {
      cout << n << " is normal." << endl;
      continue;
    }
    
    vector<int> pf = factor(n);
    if (pf.size() == 1 or adjacent_find(pf.begin(), pf.end()) != pf.end()) {
      cout << n << " is normal." << endl;
      continue;
    }

    bool flag = true;
    for (int& p : pf) {
      if ((n - 1) % (p - 1) != 0)
	flag = false;
      if (!flag)
	break;
    }

    if (flag)
      cout << "The number " << n << " is a Carmichael number."  << endl;
    else
      cout << n << " is normal." << endl;
  }
  
  return 0;
}
