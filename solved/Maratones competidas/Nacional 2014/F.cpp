/**
*  UTP BMO
*/
using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = "<<(x)<<endl
#define endl '\n'

const int MN = 1010;
int g[MN][MN];
int d[MN];

struct mio{
    int v;
    mio(){}
    mio(int a) : v(a){}
    bool operator < (const mio &o) const {
        return v < o.v;
    }
};

int main() { ___

    #ifdef BMO
        freopen("f.in", "r", stdin);
    #endif

    int n;
    while (cin>>n) {
        memset(g, 0, sizeof g);
        memset(d, 0, sizeof d);
        priority_queue<mio> q;
        for (int i = 0; i < n; ++i) {
            cin>>d[i];
            q.push(mio(d[i]));
        }
        int ok = 1;
        while (!q.empty()) {
            if (q.size() == 1) {
                ok = 0;
                break;
            }
            int cur = q.top().v;
            q.pop();
            if (q.size() < cur) {
                ok = 0;
                break;
            }
            vector<int> tmp;
            while (cur--) {
                tmp.push_back(q.top().v);
                q.pop();
            }

            for (int i = 0; i < tmp.size(); ++i) {
                if (tmp[i] > 1)
                    q.push(mio(tmp[i] - 1));
            }
        }

        cout<<ok<<endl;
    }

    return 0;
}

