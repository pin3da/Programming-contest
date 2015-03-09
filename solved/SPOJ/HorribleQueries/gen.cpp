#include <cstdio>
#include <cstdlib>
#include <ctime>


#if 1
#define MAXT 5
#define MAXN 100000
#define MAXQ 100000
#define MAXV 10000000
#define NL   0
#endif

#if 0
#define MAXT 20
#define MAXN 100000
#define MAXQ 100000
#define MAXV 100000000
#define NL   1
#endif


void test_case()
{
#if NL
    puts("");
#endif

    int n = rand() % MAXN + 1;
    int q = rand() % MAXQ + 1;

    printf("%d %d\n", n, q);
    while (q--) {
        int com = rand() % 2;

        if (com == 0) {
            int y = rand() % n;
            int x = rand() % (y + 1);
            int v = rand() % MAXV + 1;
            printf("%d %d %d %d\n", com, x, y, v);
        }
        else {
            int y = rand() % n;
            int x = rand() % (y + 1);
            printf("%d %d %d\n", com, x, y);
        }
    }
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    while (T--) test_case();

    return 0;
}
