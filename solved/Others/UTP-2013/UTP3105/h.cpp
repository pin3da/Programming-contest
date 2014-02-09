using namespace std;
#include<iostream>
#define For(i,n) for(int i=0;i<n;++i)

int main(){
	int n;
	while(cin>>n && n){
		char grille[n][n];
		char mess[n][n];
		For(i,n)
			For(j,n)
				cin>>grille[i][j];
		For(i,n)
			For(j,n)
				cin>>mess[i][j];
		//Grille roted 0
		For(i,n)
			For(j,n)
				if(grille[i][j]=='O')
					cout<<mess[i][j];
		//Grille roted 1
		int t=0;
		For(i,n){
			t=0;
			for(int j=n-1; j>=0; --j,++t)
				if(grille[j][i]=='O')
					cout<<mess[i][t];
		}
		//Grille roed 2;
		int t1=0;
		for(int i = n-1;i>=0;--i,++t1){
			t=0;
			for(int j=n-1; j>=0; --j,++t)
				if(grille[i][j]=='O')
					cout<<mess[t1][t];
		}
		//Grille roed 3;
		t=0;
		for(int i = n-1;i>=0;--i,++t){
			For(j,n)
				if(grille[j][i]=='O')
					cout<<mess[t][j];
		}
		cout<<endl;
	}
	return 0;
}
