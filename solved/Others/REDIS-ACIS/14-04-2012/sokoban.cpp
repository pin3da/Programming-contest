using namespace std;
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

#include<cstdio>
#include<cstdlib>
#include<cmath>

#define MAX_double 1.79769e+308

#define For(i,k) for(int i=0; i< (k) ; ++i) 

#define FILE_IN "sokoban"

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS){
	return (x <= y + tol) ? ( x+ tol < y) ? -1 : 0 : 1;
}

typedef pair<int , int > pii;
typedef long long ll;

char MP[15][15];
int px,py;


void horizontal(int K){
	char tmp;
	if(MP[px][py-K]=='#')return;
	if(MP[px][py-K]=='.'){
		if(MP[px][py]=='W')
		    MP[px][py] = '+';
		else
			MP[px][py] = '.';
		MP[px][py-K] = 'w';
		py-=K;
		return;
	}

	if(MP[px][py-K]=='+'){
		if(MP[px][py]=='W')
		    MP[px][py] = '+';
		else
			MP[px][py] = '.';
		MP[px][py-K] = 'W';
		py-=K;
		return;
	}
	
	if(MP[px][py-K]=='b'){
		if(MP[px][py-(K*2)]=='b' or MP[px][py-(K*2)]=='B' or MP[px][py-(K*2)]=='#')
			return;
		if(MP[px][py-(K*2)]=='+'){
			MP[px][py-(K*2)]='B';
		}else{
			MP[px][py-(K*2)]='b';
		}
			
		if(MP[px][py]=='W'){
		    MP[px][py] = '+';	
		}else{
			MP[px][py] = '.';
		}
		MP[px][py-K] = 'w';
		py-=K;
		return;
	}

	if(MP[px][py-K]=='B'){
		if(MP[px][py-(K*2)]=='b' or MP[px][py-(K*2)]=='B' or MP[px][py-(K*2)]=='#')
			return;
		if(MP[px][py-(K*2)]=='+'){
			MP[px][py-(K*2)]='B';
		}else{
			MP[px][py-(K*2)]='b';
		}
			
		if(MP[px][py]=='W')
		    MP[px][py] = '+';	
		else
			MP[px][py] = '.';
		MP[px][py-K] = 'W';
		py-=K;
		return;
	}
	
}

void vertical(int K){
	char tmp;
	if(MP[px-K][py]=='#')return;
	if(MP[px-K][py]=='.'){
		if(MP[px][py]=='W')
		    MP[px][py] = '+';
		else
			MP[px][py] = '.';
		MP[px-K][py] = 'w';
		px-=K;
		return;
	}

	if(MP[px-K][py]=='+'){
		if(MP[px][py]=='W')
		    MP[px][py] = '+';
		else
			MP[px][py] = '.';
		MP[px-K][py] = 'W';
		px-=K;
		return;
	}
	
	if(MP[px-K][py]=='b'){
		if(MP[px-(K*2)][py]=='b' or MP[px-(K*2)][py]=='B' or MP[px-(K*2)][py]=='#')
			return;
		if(MP[px-(K*2)][py]=='+'){
			MP[px-(K*2)][py]='B';
		}else{
			MP[px-(K*2)][py]='b';
		}
			
		if(MP[px][py]=='W')
		    MP[px][py] = '+';	
		else
			MP[px][py] = '.';
		MP[px-K][py] = 'w';
		px-=K;
		return;
	}

	if(MP[px-K][py]=='B'){
		if(MP[px-(K*2)][py]=='b' or MP[px-(K*2)][py]=='B' or MP[px-(K*2)][py]=='#')
			return;
		if(MP[px-(K*2)][py]=='+'){
			MP[px-(K*2)][py]='B';
		}else{
			MP[px-(K*2)][py]='b';
		}
			
		if(MP[px][py]=='W')
		    MP[px][py] = '+';	
		else
			MP[px][py] = '.';
		MP[px-K][py] = 'W';
		px-=K;
		return;
	}
}



int main(){
	//freopen(FILE_IN ".in","r",stdin);
	int rows, cols, game=0;
	char tmp;
	int win=1,w2=1;
	string cad;
	while(true){
		cin>>rows>>cols;
        game++;
		win=1;
		if(rows==cols and rows==0)break;
		For(i,rows){
			For(j,cols){
			    cin>>tmp;
			    if(tmp=='w' or tmp=='W'){
				px=i;
				py=j;
			    }
			    MP[i][j]=tmp;
			}
		}
		cin>>cad;
		For(i,cad.size()){
			if(cad[i]=='U')vertical(1);
			if(cad[i]=='D')vertical(-1);
			if(cad[i]=='R')horizontal(-1);
			if(cad[i]=='L')horizontal(1);
			w2=1;
			For(k,rows){
				For(j,cols)
					if(MP[k][j]=='b'){
						w2=0;
						break;
					}
            	//cout<<endl;
			}
			//cout<<"w2 "<<w2<<endl;
			if(w2)break;

			//cout<<endl<<endl;
		}
        For(i,rows)
			For(j,cols)
				if(MP[i][j]=='b'){
					win=0;
					break;
				}
                
        cout<<"Game "<<game<<": "<<((win)?"complete":"incomplete")<<endl;
		For(i,rows){
			For(j,cols)
				cout<<MP[i][j];
            cout<<endl;
		}
	}
	
	
	return 0;
}
