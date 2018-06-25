#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;


typedef long long i64;


int A, B, C, x1, x2, y1, y2;


template<typename T>
T gcd(T a, T b) { for (T c = a%b; c != 0; a=b,b=c,c=a%b); return b; }

template<typename T>
void ext_euclid(T a, T b, T &x, T &y, T &g) {
    x = 0; y = 1; g = b;
    T m, n, q, r;
    for (T u=1, v=0; a != 0; g=a, a=r) {
        q = g / a; r = g % a;
        m = x-u*q; n = y-v*q;
        x=u; y=v; u=m; v=n;
    }
}


i64 a_and_b_zero()
{
    if (C != 0) return 0;
    i64 res = x2 - x1 + 1;
    res *= y2 - y1 + 1;
    return res;
}

i64 a_or_b_zero()
{
    if (A == 0) {
        swap(A, B);
        swap(x1, y1);
        swap(x2, y2);
    }
    if (C % A != 0) return 0;
    int q = -C / A;
    if (x1 <= q && q <= x2) return y2 - y1 + 1;
    return 0;
}

template <typename T>
T sgn(T x)
{
    if (x == 0) return 0;
    return x < 0 ? -1 : 1;
}

i64 div_ceil(i64 a, i64 b)
{
    if (a % b == 0) return a / b;
    i64 s = sgn(a)*sgn(b);
    i64 q = a / b;
    return s > 0 ? q + 1 : q;
}
i64 div_floor(i64 a, i64 b)
{
    if (a % b == 0) return a / b;
    i64 s = sgn(a)*sgn(b);
    i64 q = a / b;
    return s > 0 ? q : q - 1;
}

i64 solve()
{
    if (A == 0 && B == 0) return a_and_b_zero();
    if (A == 0 || B == 0) return a_or_b_zero();

    int g = gcd(max(A, B), min(A, B));
    if (C % g != 0) return 0;

    int x0, y0, g0;
    ext_euclid(A/g, B/g, x0, y0, g0);
    g *= g0;

    if (sgn(g) * sgn(B) < 0) swap(x1, x2);
    i64 lo1 = div_ceil(1LL * g * x1 + 1LL * C * x0, B);
    i64 hi1 = div_floor(1LL * g * x2 + 1LL * C * x0, B);

    if (sgn(g) * sgn(-A) < 0) swap(y1, y2);
    i64 lo2 = div_ceil(1LL * g * y1 + 1LL * C * y0, -A);
    i64 hi2 = div_floor(1LL * g * y2 + 1LL * C * y0, -A);

    i64 lo = max(lo1, lo2);
    i64 hi = min(hi1, hi2);

    if (lo <= hi) return hi - lo + 1;
    return 0;
}

int main()
{
    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%d%d%d%d%d%d%d", &A, &B, &C, &x1, &x2, &y1, &y2);
        printf("Case %d: %lld\n", ++ncase, solve());
    }

    return 0;
}

