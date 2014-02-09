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
        map<int,int> markers[MP];
        map<int,int> caps[MP];

        for(int i = 0; i< n; ++i){
            int a,b;cin>>a>>b;
            markers[b][a]++;
        }
        int u =0 , v = 0;

        vector<pair<int,int> > pend;

        for(int i = 0; i <m; ++i){
            int a,b;cin>>a>>b;
            if(markers[b].count(a) > 0){
                u++;
                v++;
                markers[b][a]--;
                if(markers[b][a]==0)
                    markers[b].erase(a);

            }else{
                pend.push_back(make_pair(b,a));
            }
        }


        for(int i = 0; i< pend.size(); ++i){
            int b = pend[i].first;
            int a = pend[i].second;
            if(markers[b].size() > 0){
                u++;
                markers[b].erase(markers[b].begin());
            }
        }
        cout<<u<<" "<<v<<endl;

    }

    return 0;
}
