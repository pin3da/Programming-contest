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
#include<cctype>

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


int main(){
    int TC;
    string buffer;
    getline(cin,buffer);
    TC = toInt(buffer);
    int primero = 1;
    while(TC--){
        if(!primero)cout<<endl;
        else primero = 0;
        
        buffer="";
        while(toStr(buffer).size()<1)getline(cin,buffer);
        int candidates = toInt(buffer);
        
        map<string,string> pertenece;
        map<string, int > votos;
        while(candidates--){
            string name,partido;
            getline(cin,name);
            getline(cin,partido);
            pertenece[name] = partido;
        }
        
        int k;
        
        buffer="";
        while(toStr(buffer).size()<1)getline(cin,buffer);
        k = toInt(buffer);
        
        int M = k;
        while(k--){
            string name;
            getline(cin,name);
            votos[name]++;
        }
        int mmax = -1;
        string winner;
        int paila = 0;
        foreach(xx, votos){
            if(xx->second == mmax){
                paila = 1;
            }
            if(xx->second > mmax){
                mmax = xx->second;
                winner = pertenece[xx->first];
                paila = 0;
            }
        }
        if(paila or M ==0){
            cout<<"tie"<<endl;
        }else
            cout<<winner<<endl;
    }
    return 0;
}
