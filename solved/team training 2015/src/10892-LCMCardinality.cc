#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  while (cin >> n and n) {
    vector<long long> divs;
    for (int i = 1; i * i <= n; i++)
      if (n % i == 0) {
	divs.push_back(i);
	if (i != n / i) divs.push_back(n / i);
      }

    int c = 1; // (n, n) is valid
    for (int i = 0; i < divs.size(); i++) {
      for (int j = i + 1; j < divs.size(); j++)
	if (divs[i] * divs[j] / __gcd(divs[i], divs[j]) == n)
	    c++;
    }

    cout << n << " " << c << endl;
  }
  
  return 0;
}
