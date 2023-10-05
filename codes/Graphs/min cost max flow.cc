const int N = 1e2+2;
int n , m;
int s , t;
int dist[N];
int path[N];
vector<int>List;

struct Edges
{
    int u , v , w , capa , flow = 0;
    bool is_used = false;
    Edges(int _u , int _v ,int _w , int _capa)
    {
        u = _u;
        v = _v;
        w = _w;
        capa = _capa;
    }

    Edges()
    {

    }

    int residual()
    {
        return capa - flow;
    }
};

vector<int>vertices[N];
vector<Edges>edge;
void AddEdge(int u , int v ,int w , int capa)
{
    edge.push_back(Edges(u , v , w , capa));
    edge.push_back(Edges(v , u , -w , 0));
    vertices[u].push_back((int)edge.size()-2);
    vertices[v].push_back((int)edge.size()-1);
}

bool Find_Path()
{
    queue<int>q;
    vector<bool>InQueue(n +1 , false);
    for(int i = 1; i <= n ; i++)
    {
        dist[i] = 1e9+7;
    }
    dist[s] = 0;
    InQueue[s] = true;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        InQueue[u] = false;
        foreach(int id in vertices[u])
        {
            if(edge[id].residual() > 0)
            {
                int v = edge[id].v;
                if(Minimize(dist[v] , dist[u] +edge[id].w ))
                {
                    path[v] = id;
                    if(InQueue[v])
                    {
                        continue;
                    }
                    q.push(v);
                    InQueue[v] = true;
                }


            }
        }
    }
    return dist[t] < 1e9+7;
}
int tot_cost = 0;
int maxFlow()
{
    int tot = 0;

    foreach(Edges &e in edge)
    {
        e.flow = 0;
    }
    while(Find_Path())
    {
        int delta = 1e9+7;
        for(int u = t ; u != s ; u = edge[path[u]].u)
        {
            Minimize(delta , edge[path[u]].residual());
        }
        tot += delta;
        for(int u = t ; u != s ; u = edge[path[u]].u)
        {
            edge[path[u]].flow += delta;
            edge[path[u] ^ 1].flow -= delta;
        }
        tot_cost += delta * dist[t];
    }
    return tot;
}

void Prepare()
{

}

void Input()
{
    cin >> n >> m;
    cin >> s >> t;
    for(int i = 1; i  <= m ; i++)
    {
        int u , v , w;
        cin >> u >>  v >> w;
        AddEdge(u , v , w , 1);
        AddEdge(v , u , w , 1);
    }
    AddEdge(n+1 , s , 0 , 2);
    s = n+1;
}


void Process()
{
    int res = maxFlow() ;
    if(res < 2)
    {
        cout << -1 ;
        return ;
    }
    cout << tot_cost <<'\n';
    s = edge[vertices[s][0]].v;
    for(int i =2 ; i >= 1 ; i--)
    {

        List.clear();
        int u = s;
        while( u!= t)
        {
            List.push_back(u);
            foreach(int id in vertices[u])
            {
                if(edge[id].is_used || edge[id].v > n || edge[id].u > n)
                {
                    continue;
                }
                int v = edge[id].v;
                if(edge[id].flow > 0)
                {
                    u = v;
                    edge[id].is_used = true;
                    break;
                }
            }
        }
        cout << (int)List.size() + 1 << ' ' ;
        foreach(int v in List)
        {
            cout << v << ' ';
        }
        cout <<t;
        cout <<'\n';
    }


}