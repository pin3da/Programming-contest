using namespace std;
#include<iostream>
#include<sstream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<cstring>
#define all(x) (x).begin(),(x).end()
#define D(x) cout<< #x " = "<<(x)<<endl

typedef long long int lli;
lli n,m;

bool mycmp(pair<lli,lli> a,pair<lli,lli> b){
    lli da = a.second - a.first;    
    lli db = b.second - b.first;
    da = (da < 0LL)? a.second - (1LL<<40) : (1LL<<40) - a.first ;
    db = (db < 0LL)? b.second - (1LL<<40): (1LL<<40) - b.first ;
    return da > db;
}

int main(){
    string line;
    while(getline(cin,line)){
        stringstream buff(line);
        buff>>n>>m;
        if(n+m == 0) break;
        vector< pair<lli,lli> > ans(n);
        string name;
        for(int i=0;i<n;++i){
            getline(cin,line);
            stringstream tmp(line);
            name = "mio";
            while(name.find(":")==string::npos)tmp>>name;
            tmp>>ans[i].first>>ans[i].second;
        }
        sort(all(ans),mycmp);
        int pin = 1;
        for(int i=0;i<n;++i){
            if(m-ans[i].first < 0){
                pin = 0;
                break;
            }
            m-=ans[i].first;
            m+=ans[i].second;
        }
        cout<<((pin)?"BENEVOLENT DICTATORSHIP":"SOCIETY RESISTS CHANGE")<<endl;
    }
    return 0;
}

