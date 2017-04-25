// http://codeforces.com/contest/149/problem/B

using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>

#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 1000

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }


map<char,int> mio;

int otro(char a){
    if(a >= '0' and a <= '9') return a - '0';
    return mio[a];
}

int check(string a,string b,int base){
    int v1 = 0;
    
    For(i,a.size()){
        if(otro(a[i])>=base)return 0;
        v1*=base;
        v1+=otro(a[i]);
    }
//    if(base==17)D(v1);
    int v2 = v1;
    v1=0;
    For(i,b.size()){
        if(otro(b[i])>=base)return 0;
        v1*=base;
        v1+=otro(b[i]);
    }
    
//    if(base==17)D(v1);
    if((v1<=59 and v2 <= 23)) return 1;
    return 0;
}

int main(){
    string a,b;
    getline(cin,a,':');
    getline(cin,b);
       
    For(i,26)
        mio[(char)(i+'A')]=10+i;
    

    int cont = 0;
    vector<int> ans;
    int bien  =0;
    int otro = 0;
    For(i,60){
        if(check(a,b,i+1)){
            ans.push_back(i+1);
            bien=1;
        }else{
            if(bien==1)
                otro = 1;
        }
    }
/*    bien = 1;
    int mio = 0;
    for(int i = 34;i<100000;++i){
        if(check(a,b,i)) mio++;
        bien ^= check(a,b,i);
    }*/
    if(ans.size()==0)
        cout<<0;
    else if(ans[ans.size()-1]==60)
        cout<<-1;
    else For(i,ans.size()) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}