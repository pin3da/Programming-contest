using namespace std;
#include<iostream>
#include<queue>
#define D(x) cout<< #x " = "<<(x)<<endl
int main(){
	int v,e,a,b;
	while(cin>>v>>e and v+e){
		vector<int> G[v];
		vector<int> in(v,0);
		for(int i=0;i<e;++i){
			cin>>a>>b;
			a--;b--;
			G[a].push_back(b);
			in[b]++;
		}
		
		queue<int> Q;
		for(int i=0;i<v;++i)
			if(in[i]==0) Q.push(i);
		
		if(Q.size()==0){
			cout<<"0"<<endl;
			continue;
		}
		int dos = Q.size() > 1;
		int cuantos=0;
		while(!Q.empty()){
			int act = Q.front();Q.pop();
			for(int i=0;i<G[act].size();++i){
				in[G[act][i]]--;
				if(in[G[act][i]]==0) Q.push(G[act][i]);
			}
			dos |= Q.size() >1;
			cuantos++;
		}
		cout<<((cuantos == v )?(dos)? 2 : 1 : 0)<<endl;
		
	
	}

	return 0;
}



