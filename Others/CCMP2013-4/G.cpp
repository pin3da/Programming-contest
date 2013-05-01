using namespace std;
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>

#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<cstring>
#define For(i,n) for(int i=0;i<(n);++i)
#define foreach(x,n) for(typeof (n).begin() x = (n).begin(); x!= (n).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<<#x " = "<<(x)<<endl

template <class T> string toStr(const T &x)
{ stringstream s;s<<x;return s.str();}
template <class T> int toInt(const T &x)
{ stringstream s; s<<x; int r; s>>r;return r;}

typedef long long int lli;



int main(){
	int l;
	while(cin>>l and l){
		string st = "+x";
		string tran;
		for(int i = 0;i< l-1; ++i){
			cin>>tran;
			if(tran=="No")continue;
			if(st ==  "+y"){
				if(tran=="+y") st = "-x";
				else if(tran=="-y") st = "+x";
				else if(tran=="+z") st = "+y";
				else if(tran=="-z") st = "+y";
			}else if(st == "-y"){
				if(tran=="+y") st = "+x";
				else if(tran=="-y") st = "-x";
				else if(tran=="+z") st = "-y";
				else if(tran=="-z") st = "-y";
			}else if(st == "+x"){
				st = tran;
			}else if(st == "-x"){
				tran[0] = (tran[0]=='-')?'+':'-';
				st = tran;
			}else if(st == "+z"){
				if(tran=="+y") st = "+z";
				else if(tran=="-y") st = "+z";
				else if(tran=="+z") st = "-x";
				else if(tran=="-z") st = "+x";
			}else if(st == "-z"){
				if(tran=="+y") st = "-z";
				else if(tran=="-y") st = "-z";
				else if(tran=="+z") st = "+x";
				else if(tran=="-z") st = "-x";
			}
		}
		cout<<st<<endl;
	}
	
	return 0;
}
