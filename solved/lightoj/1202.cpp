using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>

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
#define MP 102




int main(){
	int numcas;scanf("%d",&numcas);
	int a,b,c,d;
    for(int i=1;i<=numcas;++i){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        printf("Case %d: ",i);
        if( (a%2==b%2 and c%2!=d%2) or (a%2!=b%2 and c%2==d%2)){
            printf("impossible\n");
            continue;
        }
        if(abs(a-c) == abs(b -d)){
            printf("1\n");
            continue;
        }
        printf("2\n");
	}
	return 0;
}
