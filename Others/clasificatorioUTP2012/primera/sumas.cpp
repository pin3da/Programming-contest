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
#define Dbg if(0)
#define MAXNODES 1000
#define MP 35
#define rall()

const double pi=acos(-1);

struct point{
    int x,y;
    point() {}
    point(int X, int Y) : x(X), y(Y) {}
};

bool isvoc(char c){
    if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u')return 1;
    return 0;
}


int main(){
    vector< pair<int,int> > ans;
    int tmp;
    For(i,5){
        int acum=0;
        For(j,4){
            cin>>tmp;
            acum+=tmp;
        }
        pair<int,int> pp(acum,i);
        ans.push_back( pp );
    }

    sort(ans.rbegin(),ans.rend());
    cout<<++ans[0].second<<" "<<ans[0].first<<endl;
    return 0;
}
