using namespace std;
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); x != (v).end(); ++x)
#define MAXN 1000000000

struct edge{
    int to;
    int weight;
    edge(){}
    edge(int T,int W): to(T), weight(W){}
};

typedef vector<edge> adyacent_list;

struct node{
    long long to_root;
    adyacent_list al;
    node(): to_root(0LL){}
};


typedef map<int,node> graph;

int main(){
    //int numcas;cin>>numcas;
    //while(numcas--){
        graph g;
        int n;
        cin>>n;
        int cd[n+1];
        for(int i=0;i <= n; ++i)
            cin>>cd[i];
        int a;
        long long total=0;
        for(int i=0;i < n;++i){
            edge tmp;
            cin>>a>>tmp.to>>tmp.weight;
            total+=tmp.weight;
            g[a].al.push_back(tmp);
        }
        
        total*=2;
        
        queue<int> Q;
        Q.push(0);
        while(!Q.empty()){
            int act = Q.front();Q.pop();
            foreach(it,g[act].al){
                g[it->to].to_root = g[act].to_root + it->weight;
                Q.push(it->to);
            }
        }
        
        long long ans = (1LL<<62);
        foreach(it,g){
            ans = ((total - it->second.to_root + cd[it->first])<ans)?(total - it->second.to_root + cd[it->first]):ans;
        }
        ans = ((total + cd[0])<ans)?(total + cd[0]):ans;
        cout<<ans<<endl;
   // }
}
