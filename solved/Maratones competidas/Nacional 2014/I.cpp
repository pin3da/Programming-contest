/**
*  UTP BMO
*/
using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = "<<(x)<<endl
#define endl '\n'

const int MN = 1010;
char grid[MN][MN];
int  group[MN][MN];

int mx[4] = {1,0,-1,0};
int my[4] = {0,1,0,-1};

int r,c,s;


int flood_fill(int x, int y, int col) {

    if (x < 0) return col == 1;
    if (x >= r) return col == 0;

    if (grid[x][y] == '#') return 0;
    if (group[x][y] == -1) {
        group[x][y] = col;
        int malo = false;
        for (int i = 0; i < 4; ++i) {
            int nx = x + mx[i];
            int ny = y + my[i];

            if (ny >= 0 and ny < c and grid[nx][ny] != '#')
                malo = malo or flood_fill(nx, ny, col);
        }
        return malo;

    } else {
        return col != group[x][y];
    }

}

void debg() {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout<<group[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"---"<<endl;
}

void solve(){

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin>>grid[i][j];
        }
    }

    vector<int> input(s);
    for (int i = 0; i < s; ++i)
        cin>>input[i];

    memset(group, -1, sizeof group);

    for (int i = 0; i < c; ++i) {
        if (flood_fill(0, i, 0)) {
            cout<<0<<endl;
            return;
        }
        if (flood_fill(r - 1, i, 1)) {
            cout<<0<<endl;
            return;
        }
    }

    //debg();
    for (int i = 0; i < s; ++i) {
        int col = input[i];
        int pos = fabs(col) - 1;

        if (col > 0) {
            int row = 0;
            while (row < r and grid[row][pos] != '#') row++;
            if (row < r) {
                grid[row][pos] = '.';
                if (flood_fill(row, pos, 0)) {
                    cout<<col<<endl;
                    return;
                }
            }
        } else {
            int row = r - 1;
            while (row >= 0 and grid[row][pos] != '#') row--;
            if (row >= 0) {
                grid[row][pos] = '.';
                if (flood_fill(row, pos, 1)) {
                    cout<<col<<endl;
                    return;
                }
            }
        }
    }

    cout<<"X"<<endl;

}

int main() { ___

    #ifdef BMO
        freopen("i.in", "r", stdin);
    #endif

    while (cin>>r>>c>>s) {
        //cout<<r<<" "<<c<<" "<<s<<endl;
        solve();
    }

    return 0;
}

