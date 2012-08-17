using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<regex>
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

const double pi=acos(-1);



int main(){
	int numcas;cin>>numcas;
	int cid=0;
	regex r1("[aeiou][a-z][aiou]");
	regex r2("[aeiou][a-z][a-z](?:[a-z])[aiou]");
	while(numcas--){
		string cad;cin>>cad;
		cout<<"Case "<<++cid<<": "<<regex_replace(r1,cad,"-")<<endl;
	}
	return 0;
}
