
#include <cstdio>
#include <cstdlib>
#include <list>
#include <cmath>

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MYINF 0x3fffffff
#define rep(i,n) for(int i=0; i<(n); i++)

using namespace std;

typedef struct stAL {
    int dest;
    int c;
    int flow;
    struct stAL * sig;
} AdjNode;

typedef struct stNode {
    int node;
    char color;
    int d;
    struct stNode *pi;
    AdjNode *al;
} Nodo;

typedef struct {
    int N,E;
    Nodo nodes[1005];
    AdjNode edges[1000000];    
} Grafo;

Grafo g;
int maxmf;

void insertEdge(int u, int v, int c, int flow) {
    AdjNode *an = &g.edges[g.E++];
    an->sig = g.nodes[u].al;
    an->dest = v;
    an->c = c;
    an->flow = flow;
    g.nodes[u].al = an;   
}

void BFS(int s) {
    rep(i, g.N) {
        g.nodes[i].color = WHITE;
        g.nodes[i].d = MYINF;
        g.nodes[i].pi = 0;
    }
    g.nodes[s].color = GRAY;
    g.nodes[s].d = 0;
    g.nodes[s].pi = 0;
    list<int> q;
    q.push_front(s);
    while (q.size() != 0) {
        int u = q.back();
        q.pop_back();
        AdjNode *au;
        for (au = g.nodes[u].al;au != 0; au = au->sig) {
            int v = au->dest;
            if ((au->c - au->flow) == 0) continue;
            if (g.nodes[v].color == WHITE) {
                g.nodes[v].color = GRAY;
                g.nodes[v].d = g.nodes[u].d + 1;
                g.nodes[v].pi = &(g.nodes[u]);
                q.push_front(v);
            }            
        }
        g.nodes[u].color = BLACK;
    }
}

AdjNode *getEdge(int u, int v) {
    AdjNode *x = g.nodes[u].al;
    while (x != 0 && x->dest != v) {
        x = x->sig;
    }
    return x;
}

int mincap(int s, Nodo *x) {
    int minc = MYINF;
    while (x->pi != 0) {
        AdjNode *e = getEdge(x->pi->node,x->node);
        minc = min(minc,e->c - e->flow);
        x = x->pi;
    }
    if (x->node != s) return -1;
    return minc;
}

void augmentflow(int u, int v, int f) {
    AdjNode *x = getEdge(u,v);
    x->flow += f;
    
    x = getEdge(v,u);
    x->flow -= f;
}

int maxflow(int a, int b) {
    int f=0;
    while (true) {
        BFS(a);
        int mf = mincap(a,&g.nodes[b]);
        if (mf == -1) break;
        Nodo *x = &(g.nodes[b]);
        while (x->pi != 0) {
            int u = x->pi->node;
            int v = x->node;
            augmentflow(u,v,mf);
            x = x->pi;
        }
        f += mf;
        maxmf = max(maxmf,mf);
    }
    return f;
}

/*void testBFS(int a, int b) {
    BFS(a);
   rep(i,g.N) {
       if (g.nodes[i].pi != 0)
           printf("%d %d %d\n",g.nodes[i].node,g.nodes[i].d,g.nodes[i].pi->node);
       else
           printf("%d %d NULL\n",g.nodes[i].node,g.nodes[i].d);
   }
}*/

void testff(int a, int b) {
    int f = maxflow(a,b);
    printf("%d\n",f);
    rep(i,g.N) {
        AdjNode *x = g.nodes[i].al;
        while (x != 0) {
            printf("%d %d %d\n",i,x->dest,x->flow);
            x = x->sig;
        }
    }
}

int main() {
    int T,tcid,e,a,b;
    scanf("%d",&T);
    rep(tc,T) {
        g.E = 0; maxmf=0;
        scanf("%d %d %d %d %d",&tcid,&g.N,&e,&a,&b);
        rep(j,g.N) {
            g.nodes[j].al = 0;
            g.nodes[j].node = j;
        }
        rep(j,e) {
            int u,v,c;
            scanf("%d %d %d",&u,&v,&c);
            insertEdge(u,v,c,0);
            insertEdge(v,u,c,c);
        }
        int x = maxflow(a,b);
        double ans = ((double)x)/maxmf;
        printf("%d %.3f\n",tcid,ans);
    }
	return 0;
}
