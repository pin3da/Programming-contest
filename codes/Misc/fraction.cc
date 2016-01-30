struct frac{
  long long x, y;
  frac(long long a, long long b) {
    long long g = __gcd(a, b);
    x = a / g;
    y = b / g;
  }
  bool operator < (const frac &o) const {
    return (x * o.y < y * o.x);
  }
};
