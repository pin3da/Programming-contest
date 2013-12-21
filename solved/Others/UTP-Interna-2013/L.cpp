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

int primes[MP];
int sieve[MP];
char letras[] = {'V','A','R','R'};

int bfs(string ini,string target){
	queue<pair<string,int> > Q;
	map<string,int> visited;
	Q.push(make_pair(ini,0));
	while(!Q.empty()){
		pair<string,int> actual = Q.front();Q.pop();
		string act = actual.first;
		if(visited[act])continue;
		visited[act] = true;
		if(act == target) return actual.second;
		
		For(i,8){
			For(j,4){
				if(j%2==0){
					if(act[i] == letras[j]){
						if(i!=0 and act[i-1]=='.'){
							string otro = act;
							otro[i-1] = act[i];
							otro[i]='.';
							Q.push(make_pair(otro,actual.second+1));
							/*if(actual.second == 0){
								D(act);
								D(otro);
								cout<<endl;
							}*/
						}else if(i>1 and act[i-1]!='.' and act[i-2]=='.'){
							string otro = act;
							otro[i-2] = act[i];
							otro[i]='.';
							Q.push(make_pair(otro,actual.second+1));
						}
					}
				}else{
					if(act[i]== letras[j]){
						if(i!=7 and act[i+1]=='.'){
							string otro = act;
							otro[i+1] = act[i];
							otro[i]='.';
							Q.push(make_pair(otro,actual.second+1));
							/*if(actual.second == 0){
								D(act);
								D(otro);
								cout<<endl;
							}*/
						}else if(i<6 and act[i+1]!='.' and act[i+2]=='.'){
							string otro = act;
							otro[i+2] = act[i];
							otro[i]='.';
							Q.push(make_pair(otro,actual.second+1));
						}
					}
				}
			}
		}
	}
	return -1;

}

int main(){	
	int T;cin>>T;
	for(int tid=1;tid<=T;++tid){
		string ini,target;
		cin>>ini>>target;
		int ans = bfs(ini,target);
		if(ans == -1)
			cout<<"Caso "<<tid<<": imposible"<<endl;
		else
			cout<<"Caso "<<tid<<": "<<ans<<endl;
	}

	return 0;
}
