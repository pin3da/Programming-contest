/**
*  UTP BMO
*/
using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = "<<(x)<<endl
#define endl '\n'

const int MN = 100100;
int nums[MN];
int n;

void solve() {
    for (int i = 0; i < n; ++i)
        cin>>nums[i];

    int last = 0;
    int first = 0;
    int best = 1;
    for (int i = 1; i < n; ++i) {
        if (nums[i-1] > nums[i]) {
            best = max(best, i - first);
            first = last;
            last = i;
        }
    }
    best = max(best,(n - first));
    cout<<best<<endl;
}

int main() { ___

    #ifdef BMO
        freopen("h.in", "r", stdin);
    #endif

    while (cin>>n) {
        solve();
    }

    return 0;
}
