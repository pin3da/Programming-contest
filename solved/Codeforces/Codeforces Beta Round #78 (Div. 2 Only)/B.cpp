// http://codeforces.com/contest/99/problem/B

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

const double pi=acos(-1);
const double Pi2=acos(0);
typedef long long int lli;
typedef pair<int , int> pii;



int main(){
    int n;
    cin>>n;
    vector<int> todo(n);
    int total=0;
    For(i,n){
        cin>>todo[i];
        total+=todo[i];
    }
    int deberia = total/n;
    /*int visit[n];
    memset(visit,0,sizeof(visit));
    For(i,n){
        if(visit[i])continue;
        visit[i]=true;
        int cuanto = todo[i] - deberia;
        vector<int>::iterator it= find(all(todos),todo - cuanto);
        if(it != todo.end()){
            visit[distance(it,todo.begin())]=true;
        }
    }*/
    int exemplary = 1;
    For(i,n){
        exemplary &= todo[i]==deberia;
    }
    if(exemplary){
        cout<<"Exemplary pages."<<endl;
        return 0;
    }
    int a,b,cuanto;
    For(i,n){
        if(todo[i] != deberia){
            cuanto = todo[i] - deberia;
            a = i+1;
            int veces=0;
            for(int j=i+1;j<todo.size();++j){
                if(todo[j] == deberia - cuanto){
                    veces++;
                    b=j+1;
                }else{
                    if(todo[j] != deberia){
                        veces = -1;
                        break;
                    }
                }
            }
            if(veces==-1 or veces > 1){
                cout<<"Unrecoverable configuration."<<endl;
                return 0;
            }
            break;
        }
    }
    if(cuanto>0)swap(a,b);


    if(fabs(cuanto) >= 1 and total>1 and a>0 and a<=n and b>0 and b<=n)
        cout<<fabs(cuanto)<<" ml. from cup #"<<a<<" to cup #"<<b<<"."<<endl;
    else
        cout<<"Unrecoverable configuration."<<endl;
    return 0;
}