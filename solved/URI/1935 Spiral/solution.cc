#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

long long f(long long n, long long x) {
  return x + ((n * x) << 1) - (x * (x + 1));
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n, b;
  while (cin >> n >> b) {
    long long lo = 0, hi = n;
    while (lo < hi) {
      long long mid = (lo + hi + 1) >> 1;
      if (f(n, mid) <= b)
        lo = mid;
      else
        hi = mid - 1;
    }
    long long x, y;
    b -= f(n, lo);
    if ((lo & 1) == 0) {
      if (lo == 0) {
        x = y = 0;
        b--;
        if (b > n - 1) {
          x += n - 1;
          b -= n - 1;
          y += b;
        } else {
          x += b;
        }
      } else {
        x = (lo >> 1) - 1;
        y = lo >> 1;
        long long dx = n - lo;
        if (b > dx) {
          x += dx;
          b -= dx;
          y += b;
        } else {
          x += b;
        }
      }

    } else {
      x = n - ((lo + 1) >> 1);
      y = n - ((lo + 1) >> 1);
      long long dx = n - lo;
      long long dy = n - lo - 1;
      if (b > dx) {
        x -= dx;
        b -= dx;
        y -= b;
      } else {
        x -= b;
      }
    }
    cout << y  + 1 << ' ' << x + 1 << endl;
  }
  return 0;
}

