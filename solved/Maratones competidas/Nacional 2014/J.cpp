/**
*  UTP BMO
*/
using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = "<<(x)<<endl
#define endl '\n'

string a, b;

int play(char c, char d) {
    if (c == 'S') {
        if (d == 'S') return 0;
        if (d == 'P') return 1;
        if (d == 'R') return -1;
    }
    if (c == 'P') {
        if (d == 'S') return -1;
        if (d == 'P') return 0;
        if (d == 'R') return 1;
    }
    if (c == 'R') {
        if (d == 'S') return 1;
        if (d == 'P') return -1;
        if (d == 'R') return 0;
    }
}


int compute_outcome() {
    int ans = 0;
    for (int i = 0; i < a.size(); ++i) {
        ans += play(a[i], b[i]);
    }
    return ans;
}

double cmp(double x, double y, double tol = 1e-9) {
    return (x <= y + tol )? (x + tol < y) ? -1 : 0: 1;
}


char next(char c) {
    if (c == 'S') return 'R';
    if (c == 'P') return 'S';
    if (c == 'R') return 'P';
}

double p, s, r;

double dp[10101][10];
int visited[10101][10];

double go(int i, char cur) {
    if (i == a.size()) {
        return 0;
    }

    if  (visited[i][cur])
      return dp[i][cur];


    visited[i][cur] = true;
    int game = play(cur, b[i]);
    if (game == 1) {
        return dp[i][cur] = (1 + go(i + 1, next(cur)));
    } else if (game == -1){
        return dp[i][cur] = (-1 + go( i + 1, next(b[i])));
    }

    double ans = 0;
    ans += go(i + 1, 'P') * p;
    ans += go(i + 1, 'R') * r;
    ans += go(i + 1, 'S') * s;

    return dp[i][cur] = ans;


}
int main() { ___

    #ifdef BMO
        freopen("j.in", "r", stdin);
    #endif

    int n;cin>>n;
    while (n--) {
        memset(visited, 0, sizeof  visited);
        cin>>a>>b;

        int rr,pp,ss;
        cin>>rr>>pp>>ss;
        r = rr/100.0;
        p = pp/100.0;
        s = ss/100.0;

        int first = compute_outcome();
        double second = go(0, 'P') * p + go(0, 'R') * r + go(0, 'S') * s;

        printf("%d %.4lf ", first, second);
        if (cmp(second, first) == 1)
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}


