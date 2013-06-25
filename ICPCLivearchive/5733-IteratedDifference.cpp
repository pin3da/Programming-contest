/**
* Manuel Pineda.
* Accepted.
* 0.108 s
*/

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
#define MAXNODES 1000
#define MAX(a,b) ((a>b)?(a):(b))

typedef pair<int,int> pii;

int main(){
    int a,cid=0;
    while(cin>>a and a){
       vector<int> todo(a);
       For(i,a)cin>>todo[i];
       int iter=0,pin=1;
       while(iter<1001 and pin){ 
            int val=todo[0];
            int mp=1;
            For(i,a) 
                if(todo[i]!=val){
                    mp=0;
                    break;
                }
            if(mp)pin=0;
            For(i,a-1)
                todo[i] = fabs(todo[i]-todo[i+1]);
            todo[a-1] = fabs(todo[a-1]-val);
            iter++;
       }
       cout<<"Case "<<++cid<<": ";
       if(iter<1001){
            cout<<iter-1<<" iterations\n";
       }else{
            cout<<"not attained\n";
       }
            
    }
	return 0;
}
