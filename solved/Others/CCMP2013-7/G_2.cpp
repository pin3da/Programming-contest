using namespace std;
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<cassert>
#include<map>
#include<queue>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<climits>

#define For(i,n) for(int  i= 0 ; i<n;++i)
#define D(x) cout<< #x " = " <<(x)<<endl
#define MAXNODES 2510

struct point{
    double x,y;
    point(){}
    point(double a, double b): x(a),y(b){}
    bool operator < (const point & that) const{
        if(x == that.x) return y < that.y;
        return  x < that.x;
    }
};

double get_dist(point a,point b){
    double x = a.x - b.x;
    double y = a.y - b.y;
    return x*x + y*y ;
}

point start;
point termina;
int final,inicial;



struct edge{
    int to;
    double w;
    edge(){}
    edge(int t, double _w): to(t),w(_w){}
    bool operator < (const edge &that) const{
        return w < that.w;
    }
};

vector<edge> g[MAXNODES];

double d[MAXNODES];
int p[MAXNODES];

const double oo = 1e100;

double dijsktra(int s,int n){
    //s nodo inicial, n numero nodos
    for(int i = 0 ; i< n ; ++i){
        d[i] =  oo;
        p[i] = -1;
    }
    d[s] = 0;
    priority_queue<edge> Q;
    Q.push(edge(s,0));
    while(!Q.empty()){
        int node = Q.top().to;
        double dist = Q.top().w;
        Q.pop();
        if(dist > d[node])continue;
        if(node == final)
            return dist;
        for(int i = 0; i < g[node].size(); ++i){
            int to = g[node][i].to;
            double w_extra = g[node][i].w;
            if(dist + w_extra < d[to]){
                d[to] = dist + w_extra;
                p[to] = node;
                Q.push(edge(to, d[to]));
            }
        }
    }
    return oo;
}
///////////end dijsktra///////////////


struct edge_k{
    int start, end;
    double weight;
    edge_k(int a,int b,double c): start(a), end(b), weight(c){}
    bool operator <(const edge_k &o) const{
        return weight < o.weight;
    }
    
};

int p_k[MAXNODES];
int rank[MAXNODES];
void make_set(int x){ p_k[x] = x; rank[x] = 0;}
void link(int x, int y){
    if(rank[x] > rank[y]) p_k[y] = x;
    else{p_k[x] = y; if(rank[x] == rank[y]) rank[y]++;}
}
int find_set(int x){
    return x != p_k[x] ? p_k[x] = find_set(p_k[x]) : p_k[x];
}
void merge(int x, int y){ link(find_set(x), find_set(y));}

double kruskal(vector<edge_k> &e,int n){
    double total = 0;
    sort(e.begin(), e.end());
    for(int i = 0; i <= n; ++i)
        make_set(i);
        
    for(int i = 0; i < e.size(); ++i){
        int u = e[i].start, v = e[i].end;
        double w = e[i].weight;
        if(find_set(u) != find_set(v)){
            total += w;
            merge(u,v);
            g[u].push_back(edge(v,w));
            g[v].push_back(edge(u,w));
        }
    }
    return total;
}



void print_path(int node){
    if(p[node]==inicial)
        cout<<node<<endl;
    else{
        print_path(p[node]);
        cout<<node<<endl;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nodes;
    int primero = 1;
    while(cin>>nodes and nodes !=-1){
        vector<point> todos(nodes);
        int x, y;
        map<point,int> code;
        For(i,nodes){
            cin>>x>>y;
            todos[i] = point(x,y);
            code[point(x,y)] = i;
        }
        cin>>x>>y;
        start =  point(x,y);
        todos.push_back(start);
        code[start] = nodes;
        
        cin>>x>>y;
        termina = point(x,y);
        code[termina] = nodes +1;
        todos.push_back(termina);
        
        For(i,nodes+2)g[i].clear();
        vector<edge_k> edges;
        For(i,todos.size()){
            for(int j = i+1 ; j< todos.size(); ++j){
//            For(j,todos.size()){
                    double dist = get_dist(todos[i], todos[j]);
                    edges.push_back(edge_k(i,j,dist));
            }
        }
        
       /* For(i, nodes+2){
            For(j,g[i].size()){
                cout<<"to "<< g[i][j].to<<" we "<<g[i][j].w<<endl;
            }
        }*/
        final = code[termina];
        inicial = code[start];
        kruskal(edges,todos.size());
        
        /*
        For(i,nodes +2){
            cout<<"Node "<<i<<": "<<endl;
            For(j, g[i].size()){
                cout<<" "<<g[i][j].to;
            }
            cout<<endl;
        }*/
        
        double ans = dijsktra(code[start],nodes+2);
        if(primero)primero = 0;
        else cout<<endl;
        if(p[final]==inicial)cout<<"-"<<endl;
        else print_path(p[code[termina]]);
        
       
    }
       
        
    return 0;
}

