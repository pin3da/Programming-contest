#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  while (n--) {
    long long a, b, c, d;
    char op, tmp;
    cin >> a >> tmp >> b >> op >> c >> tmp >> d;
    if (op == '+') {
      long long num = (a * d + b * c);
      long long den = (b * d);
      cout << num << '/' << den << " = ";
      long long g = __gcd(num, den);
      cout << num / g << '/' << den / g << endl;
    }

    if (op == '-') {
      long long num = (a * d - b * c);
      long long den = (b * d);
      if (den < 0) {
        den *= -1;
        num *= -1;
      }
      cout << num << '/' << den << " = ";
      long long g = __gcd(llabs(num), llabs(den));
      cout << num / g << '/' << den / g << endl;
    }

    if (op == '*') {
      long long num = (a * c);
      long long den = (b * d);
      if (den == -1) {
        den *= -1;
        num *= -1;
      }
      cout << num << '/' << den << " = ";
      long long g = __gcd(num, den);
      cout << num / g << '/' << den / g << endl;
    }

    if (op == '/') {
      long long num = (a * d);
      long long den = (c * b);
      if (den == -1) {
        den *= -1;
        num *= -1;
      }
      cout << num << '/' << den << " = ";
      long long g = __gcd(num, den);
      cout << num / g << '/' << den / g << endl;
    }
  }
  return 0;
}
