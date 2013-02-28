using namespace std;
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#include<set>
#include<map>

#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#define For(i,n) for(int i=0;i<(n);++i)
#define all(x) x.begin(),x.end()
#define D(x) cout<<#x " = "<<(x)<<endl
#define white 0
#define gray 1
#define black 2

char grid[101][101];
int n;
vector<int> solve(int pos,int col=0){
	vector<int> ans;
	int a,b;
	int acum = 0;
	For(i,n){
		a = pos; b = i;
		if(col) swap(a,b);
		if(grid[a][b]=='X'){
				acum++;
		}else{
			if(acum!=0)
				ans.push_back(acum);
			acum = 0;
		}
	}
	if(acum!=0)
		ans.push_back(acum);
	
	if (ans.size()==0) ans.push_back(0);
	return ans;
}

int main(){
	while(cin>>n and n){
			For(i,n){
				For(j,n){
					cin>>grid[i][j];
				}
			}
			vector<int> ans[n<<1];
			For(i,n){
				ans[i] = solve(i);
			}
			For(i,n){
				ans[n+i] = solve(i,1);
			}
			For(i,2*n){
				For(j,ans[i].size()){
					cout<<ans[i][j]<<((j==ans[i].size()-1)?"":" ");
				}
				cout<<endl;
			}
	}
	return 0;
}
