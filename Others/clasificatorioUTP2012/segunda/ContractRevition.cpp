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
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 1000

const double pi=acos(-1);

struct point{
    int x,y;
    point() {}
    point(int X, int Y) : x(X), y(Y) {}
};

string remzero(string cad){
    int i=0;
    for(i=0;i<cad.size();++i)
        if(cad[i]!='0')
            break;

    return cad.substr(i);
}

int main(){
    string cad;char f;
    while(true){
        cin>>f>>cad;
        if(f=='0' && cad=="0")break;
        foreach(x,cad){
            if((*x)==f){
                cad.erase(x);
                x--;
            }
        }
        cad=remzero(cad);
        cout<<((cad.size()>0)?cad:"0")<<endl;
    }


    return 0;
}
