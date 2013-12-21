/**
* Solved by Andrés Felipe Ruiz
*/
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

int n, m, maxRadius;
bool marks[110];
int cod[20], decod[110];
int dp[2000];
int sorted[110];

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a :b;
}

int can(int bitmask, int radius, int indexFirst) {
    for (int i=cod[indexFirst] ; i<n ; i+=radius) {
        if (!marks[i]) return 0;
        bitmask |= (1 << decod[i]);
    }
    return bitmask;
}

int findFirstUnmarked(int bitmask) {
    for (int i=0 ; i<m ; i++)
        if (!(bitmask & (1 << i)))
            return i;
}

bool canUseRadius(int radius, int pos) {
    while (pos >= 0) {
        if (!marks[pos]) return false;
        pos -= radius;
    }

    return true;
}

const char* pb(int n) {
    std::string b = "";
    for (int i=0 ; i<m ; i++) {
        if (n & (1 << i))
            b += "1";
        else
            b += "0";
    }
    return b.c_str();
}

int solve(int bitmask) {
    if (bitmask == ((1 << m) - 1)) {
        return 0;
    }
    if (dp[bitmask] != -1) return dp[bitmask];
    int ans = 1e9;
    int indexFirst = findFirstUnmarked(bitmask);
    for (int r=1 ; r <= maxRadius ; r++) {
        if (!canUseRadius(r, cod[indexFirst])) continue;
        int newBitmask = can(bitmask, r, indexFirst);
        if (newBitmask) {
            ans = min(ans, 1 + solve(newBitmask));
        }
    }

    return dp[bitmask] = ans;
}

int main() {
    while (scanf("%d %d", &n, &m) == 2) {
        // printf("%d\n", (1 << m) -1);
        memset(marks, false, sizeof marks);
        for (int i=0 ; i<m ; i++) {
            int mark;
            scanf("%d", &mark);
            sorted[i] = mark;
        }
        std::sort(sorted, sorted+m);
        for (int i=0 ; i<m ; i++) {
            int mark = sorted[i];
            marks[mark] = true;
            cod[i] = mark;
            decod[mark] = i;
        }


        memset(dp, -1, sizeof dp);
        maxRadius = n+1;
        printf("%d\n", solve(0));
    }
}
