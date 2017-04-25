// http://codeforces.com/contest/368/problem/A

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl
#define all(x) (x).begin(),(x).end()

int main(){ ___

    int n,d;
    while(cin>>n>>d){
        vector<int> cost(n);
        for(int i = 0; i< n; ++i)cin>>cost[i];
        sort(all(cost));
        int m;cin>>m;
        int profit = 0;
        int i = 0;
        while(i < n and m){
            profit += cost[i];
            i++;
            m--;
        }
        while(m--){
            profit -= d;
        }
        cout<<profit<<endl;
    }

    return 0;
}