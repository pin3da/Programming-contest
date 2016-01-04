#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
using namespace std;


#define MAXLEN 1000
#define MOD    1000007

#define Zero(v) memset((v), 0, sizeof(v))
#define Neg(v)  memset((v), -1, sizeof(v))


// llcs[i][j] will be the length of the LCS of s(0 .. i), t(0 .. j)
int llcs[MAXLEN + 1][MAXLEN + 1];

// list of characters used by s and t
char cs[26];

// length of longest LCS
int longest;

// number of distinct characters
int nc;

// xnxt[c][i] has the index of the next c from position i in string x
int snxt[26][MAXLEN];
int tnxt[26][MAXLEN];

bool used[26];

// dlcs[i][j] contains the number of distinct LCS from s(i .. ls), t(j .. lt)
int dlcs[MAXLEN + 1][MAXLEN + 1];

char s[MAXLEN + 1], t[MAXLEN + 1];
int ls, lt;


int distinct(int i, int j)
{
    if (llcs[i][j] == longest) return 1;
    if (i >= ls || j >= lt) return 0;
    if (dlcs[i][j] >= 0) return dlcs[i][j];

    dlcs[i][j] = 0;

    for (int k = 0; k < 26; ++k) {
        int is = snxt[k][i];
        int it = tnxt[k][j];

        if (is < 0 || it < 0) continue;

        if (llcs[is + 1][it + 1] == llcs[i][j] + 1) {
            dlcs[i][j] += distinct(is + 1, it + 1);
            dlcs[i][j] %= MOD;
        }
    }

    return dlcs[i][j];
}

int solve()
{
    Zero(used);
    nc = 0;
    for (int i = 0; i < ls && nc < 26; ++i)
        if (! used[s[i] - 'a']) {
            used[s[i] - 'a'] = true;
            cs[nc++] = s[i];
        }
    for (int i = 0; i < lt && nc < 26; ++i)
        if (! used[t[i] - 'a']) {
            used[t[i] - 'a'] = true;
            cs[nc++] = t[i];
        }

    for (int i = 1; i <= ls; ++i)
        for (int j = 1; j <= lt; ++j) {
            llcs[i][j] = max(llcs[i][j - 1], llcs[i - 1][j]);
            if (s[i - 1] == t[j - 1])
                llcs[i][j] = max(llcs[i][j], llcs[i - 1][j - 1] + 1);
        }

    longest = llcs[ls][lt];

    for (int k = 0; k < nc; ++k) {
        int idx = -1;
        for (int j = ls - 1; j >= 0; --j) {
            if (s[j] == cs[k]) idx = j;
            snxt[cs[k] - 'a'][j] = idx;
        }
        idx = -1;
        for (int j = lt - 1; j >= 0; --j) {
            if (t[j] == cs[k]) idx = j;
            tnxt[cs[k] - 'a'][j] = idx;
        }
    }

    Neg(dlcs);
    return distinct(0, 0);
}

int main()
{
    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%s%s", s, t);
        ls = strlen(s);
        lt = strlen(t);

        printf("Case %d: %d\n", ++ncase, solve());
    }

    return 0;
}
