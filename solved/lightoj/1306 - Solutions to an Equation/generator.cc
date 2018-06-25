#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;


#if 0
#define MAXT  10000
#define MINI -100000000
#define MAXI  100000000
#define MINA -1000
#define MAXA  1000
#define MAXR  10000
#endif

#if 1
#define MAXT  100
#define MINI -1000
#define MAXI  1000
#define MINA -100
#define MAXA  100
#define MAXR  33
#endif


const int IRange = MAXI - MINI + 1;
const int ARange = MAXA - MINA + 1;


typedef long long i64;


bool valid(i64 n)
{
    return n >= MINI && n <= MAXI;
}

void gen1()
{
    int A = rand() % ARange + MINA;
    int B = rand() % ARange + MINA;

    i64 x0, y0, x1, y1, x2, y2;
    i64 C;
    do {
        x0 = rand() % IRange + MINI;
        y0 = rand() % IRange + MINI;
        C = -1LL * (x0*A + y0*B);
    } while (! valid(x0 - MAXR) || ! valid(x0 + MAXR) ||
             ! valid(y0 - MAXR) || ! valid(y0 + MAXR) ||
             ! valid(C));

    x1 = x0 - (rand() % MAXR + 1);
    x2 = x0 + (rand() % MAXR + 1);
    y1 = y0 - (rand() % MAXR + 1);
    y2 = y0 + (rand() % MAXR + 1);

    printf("%d %d %lld %lld %lld %lld %lld\n", A, B, C, x1, x2, y1, y2);
}

void gen2()
{
    int A = rand() % IRange + MINI;
    int B = rand() % IRange + MINI;
    int C = rand() % IRange + MINI;
    int x1 = rand() % IRange + MINI;
    int x2 = rand() % IRange + MINI;
    int y1 = rand() % IRange + MINI;
    int y2 = rand() % IRange + MINI;
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    printf("%d %d %d %d %d %d %d\n", A, B, C, x1, x2, y1, y2);
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    while (T--) {
        if (rand() % 5 != 0) gen1();
        else gen2();
    }

    return 0;
}

