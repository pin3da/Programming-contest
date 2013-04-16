/***
* Not solved yet !!
*/

using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>

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

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const double pi=acos(-1);
const double Pi2=acos(0);
typedef long long int lli;
typedef pair<int , int> pii;

int dx[]={-1,-1,-1,0,0,0,1,1,1};
int dy[]={1,0,-1,1,0,-1,1,0,-1};

int main(){
    char mat[8][8];
    map<pair< pii ,int>,int> vis;
    vector<pii> pos_statues;
    For(i,8){
        For(j,8){
            cin>>mat[i][j];
            if(mat[i][j]=='S')
                pos_statues.push_back(make_pair(i,j));
        }
    }
            
            
    queue<pair< pii,int> > Q;
    Q.push(make_pair(make_pair(7,0),0));
    int win = 0;
    while(!Q.empty()){
        if(vis[Q.front()]){Q.pop();continue;}
        int time = Q.front().second;
        pii act = Q.front().first;//Q.pop();
      /*  D(act.first);
        D(act.second);
        For(i,pos_statues.size())
            cout<<pos_statues[i].first<<" , "<<pos_statues[i].second<<endl;
        cout<<endl<<endl;
        */
        vector<pii> t = pos_statues;
        vector<pii> t2;
        For(j,pos_statues.size()){
            t[j].first++;
            if(t[j].first<8)t2.push_back(t[j]);
        }
          /*      
       For(i,t2.size())
            cout<<t2[i].first<<" , "<<t2[i].second<<endl;
        cout<<endl<<endl;
            */           
        vis[Q.front()]=1;
        Q.pop();

        if(act == make_pair(0,7) or pos_statues.size()==0){
            win = 1;
            break;
        }
        int bien = 1;
        For(j,pos_statues.size()){
            if(act == pos_statues[j]){
                bien = 0;
                break;
            }
        }
        if(!bien)continue;
        For(i,9){
            if(act.first + dx[i] >=0 and act.first + dx[i] < 8 and act.second + dy[i] >=0 and act.second + dy[i] < 8){
                int bien = 1;
                For(j,t2.size()){
                    if(make_pair(act.first + dx[i],act.second + dy[i]) == t2[j]){
                        bien = 0;
                        break;
                    }
                }
                if(!bien)continue;
                For(j,pos_statues.size()){
                    if(make_pair(act.first + dx[i],act.second + dy[i]) == pos_statues[j]){
                        bien = 0;
                        break;
                    }
                }
                if(!bien)continue;
                Q.push(make_pair(make_pair(act.first + dx[i],act.second + dy[i]),time+1));
                
            }
        }
        t2.clear();
        For(j,pos_statues.size()){
             pos_statues[j].first++;
             if(pos_statues[j].first<8)t2.push_back(pos_statues[j]);
        }
        pos_statues=t2;
        
    }
    if(win)
        cout<<"WIN"<<endl;
    else
        cout<<"LOSE"<<endl;
    
    return 0;
}

