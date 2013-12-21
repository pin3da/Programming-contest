using namespace std;
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define oo 0x00FFFFFF
#define all(x) x.begin(),x.end()
#define D(x) cout<<  #x " = " <<(x)<<endl
 
int M, N, n, d, s, t;
int docs[102], answer[1 << 16];

void solve() {
    queue<int> q;
    memset(answer, 0, sizeof (answer));
    for (int i=0 ; i<M ; i++) {
        answer[docs[i]] = 1;
        q.push(docs[i]);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i=0 ; i<M; i++) {
            int v = u | docs[i];
            if (answer[v] == 0) {
                answer[v] = answer[u] + 1;
                q.push(v);
            }
        }
    }
}
 
int main() {
    while (cin>>M>>N and (M+N)) {
        for (int i = 0 ; i < M; ++i) {
            cin>>n;
            docs[i] = 0;
            for(int j = 0; j< n;++j) cin>>d, docs[i] |= (1 << (d-1));
        }
        solve();
        for(int i = 0; i< N; ++i){
            if(i > 0) cout<<" ";
            cin>>n;
            t = 0;
            for (int i = 0 ; i < n ; ++i) {
                cin>>d;
                t |= (1 << d - 1);
            }
            cout<<answer[t];
        }
        cout<<endl;
    }
}
