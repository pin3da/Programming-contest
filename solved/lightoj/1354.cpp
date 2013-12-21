using namespace std;
#include<iostream>
#include<string>
#include<sstream>
#include<climits>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<map>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(0)
#define MAXNODES 1000

string toString(int num,int size=8){
	string ans;
	for(int i=0;i<size;++i)
		ans = (((num>>i)&1)?"1":"0") + ans;
	return ans;
}

int main(){
	int numcas;scanf("%d\n",&numcas);
	int cid=0;
	string cad;
	For(k,numcas){
		string tmp,tmp2,cad;
		int num;
		cin>>tmp>>tmp2;
		For(i,tmp.size())if(tmp[i]=='.')tmp[i]=' ';
		stringstream aa(tmp);
		while(aa >> num){
			cad+="."+toString(num);
		}
		Dbg D(cad);
		Dbg D(tmp2);
		cout<<"Case "<<++cid<<": ";
		if(cad.substr(1)==tmp2)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
