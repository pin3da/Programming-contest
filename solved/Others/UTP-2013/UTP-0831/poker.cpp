using namespace std;
#include<bits/stdc++.h>
#define For(i,n) for(int i = 0; i< (n); ++i)
#define D(x) cout<< #x " = "<<(x)<<endl

char value[] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
int get_value(char a){
    for(int i = 0; i< 13; ++i)
        if(a==value[i]) return i+1;
}

int f(string hand,int n){
    int visited[15];
    memset(visited,0,sizeof visited);
    For(i,hand.size())
        visited[get_value(hand[i])]++;
    
    For(i,15)
        if(visited[i] == n) return true;
    return false;
}

int f2(string hand){
    int visited[15];
    memset(visited,0,sizeof visited);
    For(i,hand.size())
        visited[get_value(hand[i])]++;
    
    int ok = 0;
    int ok2 = 0;
    For(i,15){
        if(visited[i] == 3) ok = 1;
        if(visited[i] == 2) ok2 = 1;
    }
    return ok and ok2;
    
}
int main(){
    int tc;cin>>tc;
    For(tid,tc){
        string hand;cin>>hand;
        cout<<"UCF Hold-em #"<<tid+1<<": "<<hand<<endl;
        if(f(hand,4)){
            cout<<"Best possible hand: FOUR OF A KIND"<<endl<<endl;
            continue;
        }
        if(f2(hand)){
            cout<<"Best possible hand: FULL HOUSE"<<endl<<endl;
            continue;
        }
        if(f(hand,3)){
            cout<<"Best possible hand: THREE OF A KIND"<<endl<<endl;
            continue;
        }
        if(f(hand,2)){
            cout<<"Best possible hand: TWO OF A KIND"<<endl<<endl;
            continue;
        }
        cout<<"Best possible hand: BUST"<<endl<<endl;
    
    }
    return 0;
}
