#include <cstdio>
#include <cstdlib>
#include <ctime>


#if 1
#define MAXT 200
#define MAXLEN 1000
#endif

#if 0
#define MAXT 20
#define MAXLEN 60
#endif

char str[MAXLEN + 1];

void test_case()
{
    for (int i = 0; i < 2; ++i) {
        int len = rand() % MAXLEN + 1;

        for (int j = 0; j < len; ++j)
            str[j] = (rand() % 26) + 'a';
        str[len] = 0;

        printf("%s\n", str);
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
