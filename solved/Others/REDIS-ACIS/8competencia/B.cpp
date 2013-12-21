using namespace std;
#include<iostream>
#include<string>
#include<cmath>
#include<set>
#define For(i,n) for(int i=0;i<n;++i)
#define D(x) cout<< #x " = " <<(x)<<endl
#define Dbg if(0)
#define MP 98

int main(){
    int numcas;cin>>numcas;
    while(numcas--){
        int coins;cin>>coins;
        double t;
        int ans=0;
        For(i,coins){
            cin>>t;
            if(t==0.5)
                ans++;
        }
        Dbg D(ans);
        Dbg D(coins);
        cout<<fixed<<(long long) (pow(2.0,(double)(coins-ans))*(pow(2.0,(double)ans)-1))<<endl;
    }
    return 0;    
}

