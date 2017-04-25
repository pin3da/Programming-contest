// http://codeforces.com/contest/352/problem/A

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = "<<(x)<<endl


int main(){ ___
    int n;
    while(cin>>n){
        vector<int> veces(10,0);
        int t;
        for(int  i= 0; i <n; ++i){
            cin>>t;
            veces[t]++;
        }
        
        if(veces[5] < 9 or veces[0] == 0){
            if(veces[0]==0)
                cout<<-1<<endl;
            else
                cout<<'0'<<endl;
        }else{
            int tope = veces[5]/9;
            for(int i = 0; i < tope*9; ++i)
                cout<<5;
            for(int i = 0; i < veces[0]; ++i)
                cout<<0;
            cout<<endl;
        }
    }
    return 0;
}