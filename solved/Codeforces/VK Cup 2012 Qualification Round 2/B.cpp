// http://codeforces.com/contest/159/problem/B

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl
#define all(x) (x).begin(),(x).end()
#define MP 1010


int main (){ ___
    int n,m;
    while(cin>>n>>m){
        vector<vector<int> > a (MP, vector<int>(MP,0));
        vector<vector<int> > b (MP, vector<int>(MP,0));
        vector<int> markers(MP,0);
        vector<int> caps(MP,0);

        for(int i = 0; i< n ; ++i){
            int x,y;cin>>x>>y;
            markers[y]++;
            a[y][x]++;
        }
        for(int i = 0; i < m; ++i){
            int x,y;cin>>x>>y;
            caps[y]++;
            b[y][x]++;
        }
        int u = 0;
        int v = 0;

        for(int i = 0; i < MP; ++i){
            u += min(caps[i],markers[i]);
            for(int j = 0; j < MP; ++j){
                v+= min(a[i][j],b[i][j]);
            }
        }

        cout<<u<<" "<<v<<endl;



    }

    return 0;
}