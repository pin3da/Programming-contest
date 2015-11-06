#include<bits/stdc++.h>
using namespace std;

int my[4] = {1,0,-1,0};
int mx[4] = {0,1,0,-1};
int dir[255];
char mdirL[255],mdirR[255],mdirB[255];


void makeMove(int &x,int &y, char curd){
  x += mx[dir[curd]];
  y += my[dir[curd]];
}

void solve(string &s){
  vector<pair<int,int> > steps;
  int xmi = 100000,xma = -100000, yma = 0;
  steps.push_back({0,0});
  int curx = 0, cury = 0;
  
  char curd = 'r';
  
  for(int i = 0; i < s.size(); i++){
    if(s[i] == 'L')
      curd = mdirL[curd];
    if(s[i] == 'R')
      curd = mdirR[curd];
    if(s[i] == 'B')
      curd = mdirB[curd];
    makeMove(curx,cury,curd);
    
    steps.push_back({curx,cury});
    xmi = min(xmi,curx);
    xma = max(xma,curx);
    yma = max(yma,cury);
  }
  
  int width = abs(xma - xmi) + 2;
  
  vector<vector<char> > board(width + 1,vector<char>(yma + 2, '#'));
  cout << board.size() << " " << board[0].size() << endl;
  
  for(int i = 0; i < steps.size(); i++){
    
    int tx;
    if(steps[i].first < 0 ){
      tx = xma + abs(steps[i].first);
      board[tx + 1][steps[i].second] = '.';
    }else if(steps[i].first > 0){
      tx = xma - steps[i].first + 1;
      board[tx][steps[i].second] = '.';
    }else{
      board[steps[i].first + 1 + xma][steps[i].second] = '.';
    }
    
    //cout << steps[i].first << " " << steps[i].second << endl;
  }
  for(int i = 0; i < board.size(); i++){
    for(int j = 0; j < board[i].size(); j++) cout << board[i][j];cout<< endl;
  }

}


int main(){
  int t; cin >> t;

  dir['r'] = 0; dir['u'] = 1; dir['l'] = 2; dir['d'] = 3;
  mdirL['r'] = 'u'; mdirL['u'] = 'l'; mdirL['l'] = 'd'; mdirL['d'] = 'r';
  mdirR['r'] = 'd'; mdirR['d'] = 'l'; mdirR['l'] = 'u'; mdirR['u'] = 'r';  
  mdirB['r'] = 'l'; mdirB['l'] = 'r'; mdirB['u'] = 'd'; mdirB['d'] = 'u';  
  cout << t << endl;
  
  while( t-- ){
    string s;
    cin >> s;
    
    solve(s);
  }
}
