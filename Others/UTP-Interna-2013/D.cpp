using namespace std;
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
#include<map>

#include<cmath>
#include<cassert>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define For(i,n) for(int i=0;i<(n);++i)
#define foreach(x,n) for(typeof (n).begin() x = (n).begin(); x!= (n).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<<#x " = "<<(x)<<endl
#define MP 2000

template <class T> string toStr(const T &x)
{ stringstream s;s<<x;return s.str();}
template <class T> int toInt(const T &x)
{ stringstream s; s<<x; int r; s>>r;return r;}

int get_pos(string cad,char t){
	For(i,cad.size()){
		if(cad[i]==t) return i;
	}
}

char mat[100][100];
int dp[65][65][65][65];
int contar[30][70][70];
string proteinas;

int solve(int a,int b,int c,int d){
	if( c-a < 0 or d-b <0) 
		return 0;
	if(dp[a][b][c][d] != -1) return dp[a][b][c][d];
	int valid = 1;
	int total = 0;
	For(i,proteinas.size()){
		valid &= (contar[i][c][d] - ((a>0)?contar[i][a-1][d]:0) - ((b>0)?contar[i][c][b-1]:0) + ((a>0 and b>0)?contar[i][a-1][b-1]:0)) > 0;
		total += (contar[i][c][d] - ((a>0)?contar[i][a-1][d]:0) - ((b>0)?contar[i][c][b-1]:0) + ((a>0 and b>0)?contar[i][a-1][b-1]:0));
	}
	valid &= (total == (c-a+1)*(d-b+1));
	if(valid)
	  return dp[a][b][c][d] = (c-a+1)*(d-b+1);

	return dp[a][b][c][d] = max( solve(a,b,c,d-1), max (solve(a,b,c-1,d), max(solve(a,b+1,c,d),solve(a+1,b,c,d)) ) );
}


int main(){	
	int a,b;
	while(cin>>a>>b and a+b){
		cin>>proteinas;
		memset(contar,0,sizeof(contar));
		memset(dp,-1,sizeof(dp));
		For(i,a){
			For(j,b){
				cin>>mat[i][j];
			}
		}
		For(i,proteinas.size()){
			contar[get_pos(proteinas,proteinas[i])][0][0] = mat[0][0]==proteinas[i];
			for(int j=1;j<a;++j)
				contar[i][j][0] = contar[i][j-1][0] + (mat[j][0]==proteinas[i]);
			for(int j=1;j<b;++j)
				contar[i][0][j] = contar[i][0][j-1] + (mat[0][j]==proteinas[i]);
			
			for(int j=1;j<a;++j)
				for(int k=1;k<b;++k)
					contar[i][j][k] =  contar[i][j-1][k] + contar[i][j][k-1] - contar[i][j-1][k-1] + (mat[j][k]==proteinas[i]);

		}		
		cout<<solve(0,0,a-1,b-1)<<endl;
	}
	return 0;
}
