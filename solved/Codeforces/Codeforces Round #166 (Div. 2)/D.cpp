// http://codeforces.com/contest/271/problem/D

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef unsigned long long hash;
typedef pair<hash,hash> H;
int main(){ ___
    string cad,good;
    int k;
    while(cin>>cad>>good>>k){
        const int p = 1307,p1 = 2671;
        set<H> ans;
        for(int i = 0; i < cad.size(); ++i){
            int bad = 0;
            hash h = 0;
            hash h1 = 0;
            for(int l = 1; l + i <= cad.size(); ++l){
                h  = (h  * p) + (cad[i+l-1] - 'a' +1);
                h1 = (h1 * p) + (cad[i+l-1] - 'a' +1);
                bad += (good[cad[i+l-1] - 'a'] == '0');
                if(bad > k) break;
                ans.insert(make_pair(h,h1));
            }
        }
        cout<<ans.size()<<endl;
    }
    return 0;
}