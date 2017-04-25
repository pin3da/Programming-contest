// http://codeforces.com/contest/398/problem/B

using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<<#x " = "<<(x)<<endl

int n,m;
int seen[2112][2112];
double ans[2112][2112];

double solve(int x, int y) {
    if (seen[x][y]) return ans[x][y];
    seen[x][y] = true;
    if (x == 0 and y == 0) return ans[x][y] = 0;
    int xp = n - x;
    int yp = n - y;
    double ch_x = xp / (double) n;
    double ch_y = yp / (double) n;
    double ch_p = ch_x * ch_y;
    double ev = ch_p;
    if ((1.0 - ch_p) <= 0.0) return ans[x][y] = 0;
    if (x > 0)  ev += (1 + solve(x - 1, y)) * ch_y * (1.0 - ch_x);
    if (y > 0)  ev += (1 + solve(x, y - 1)) * (ch_x) * (1.0 - ch_y);
    if (x > 0 and y > 0) ev += (1 + solve(x - 1, y - 1)) * (1.0 - ch_x) * (1.0 - ch_y);
    return ans[x][y] = ev/(1.0 - ch_p);
}

int main() {

    cin>>n>>m;
    set<int> usedx, usedy;
    int x,y;
    for (int i = 0; i < m; ++i) {
        cin>>x>>y;
        usedx.insert(x);
        usedy.insert(y);
    }

    memset(seen, 0, sizeof seen);
    printf("%.10lf\n", solve(n-usedx.size(), n - usedy.size()) );

    return 0;
}
