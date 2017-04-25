// http://codeforces.com/contest/368/problem/B

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl
#define all(x) (x).begin(),(x).end()

int main(){ ___

    int n,m;
    while(cin>>n>>m){
        vector<int> array(n);
        for(int i = 0; i < n; ++i) cin>>array[i];
        vector<int> ans(n);
        set<int> counter;
        for(int i = n-1; i >= 0; --i){
            counter.insert(array[i]);
            ans[i] = counter.size();
        }
        int query;
        for(int i = 0; i < m; ++i){
            cin>>query;
            cout<<ans[query-1]<<endl;
        }

    }

    return 0;
}