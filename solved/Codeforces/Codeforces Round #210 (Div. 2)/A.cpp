// http://codeforces.com/contest/361/problem/A

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl
#define all(x) (x).begin(),(x).end


int main(){ ___

    int n,m;
    while(cin>>n>>m){
        for(int i = 0; i< n; ++i){
            for(int j = 0; j< n; ++j){
                if(i==j)cout<<m<<" ";
                else cout<<"0 ";
            }
            cout<<endl;
        }
    }

    return 0;
}