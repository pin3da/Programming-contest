/*
Backtraking
*/

#include <bits/stdc++.h>
using namespace std;

int n,m,ans;

pair<int,int> posible(vector<vector<bool> > &board){
	for(int i = 0; i < board.size(); i++){
		for(int j = 0; j < board[i].size(); j++)
			if(!board[i][j]) return {i,j};
	}
	return {-1,-1};
}

bool fil1(vector<vector<bool> > &board,pair<int,int> x, pair<int,int> y){
	
	int iaux = -1;
	int jaux = -1;
	for(int i = x.first; i < y.first && (iaux == -1); i++){
		for(int j = x.second; j < y.second; j++){
			if(board[i][j]){
				jaux = j;
				iaux = i;
				break;
			}
			board[i][j] = 1;
		}
	}
	if(iaux != -1){
		for(int i = x.first; i < y.first; i++){
			for(int j = x.second; j < y.second; j++){
				if(i == iaux && j == jaux) return 0;
				board[i][j] = 0;
			}
		}
	}
	
	return 1;
	
}

void cle(vector<vector<bool> > &board,pair<int,int> x, pair<int,int> y){
	
	for(int i = x.first; i < y.first; i++){
		for(int j = x.second; j < y.second; j++){
			board[i][j] = 0;
		}
	}
	
}


void backtrack(vector<vector<bool> > &board,vector<pair<int,pair<int,int> > > &p){

	pair<int,int> pos = posible(board);
	if(pos.first == -1){ ans = 1; return ;}
	
	for(int i = 0; i < p.size() && !ans; i++){
		int x = p[i].second.first + pos.first;
		int y = p[i].second.second + pos.second;
		
		int xp = p[i].second.second + pos.first;
		int yp = p[i].second.first + pos.second;
		
		if(p[i].first > 0){
			if(x <= n && y <= m){
				if(fil1(board,pos,{x,y})){
					p[i].first--;
					backtrack(board,p);
					cle(board,pos,{x,y});
					p[i].first++;
				}
				
			}
			if(xp <= n && yp <= m){
				if(fil1(board,pos,{xp,yp})){				
					p[i].first--;
					backtrack(board,p);
					cle(board,pos,{xp,yp});
					p[i].first++;
				}
			}
		}
	}
	
	return;
	
}



int main(){
    int c;
    while(cin >> n >> m >> c){
    	vector<pair<int,pair<int,int> > > piezas(c);
    	vector<vector<bool> > board(n,vector<bool>(m,0));
    	
    	for(int i = 0; i < c; i++) cin >> piezas[i].first >> piezas[i].second.first >> piezas[i].second.second;
    	
    	ans = 0;
    	backtrack(board,piezas);
    	
    	if(ans) cout << "yes" <<endl;
    	else    cout << "no" <<endl;
    }
}

