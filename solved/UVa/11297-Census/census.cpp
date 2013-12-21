using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>
#define D(x) cout<< #x " = "<<(x)<<endl



struct Segment_tree{
	vector<int> A;
	vector<int> _min;
	vector<int> _max;
	Segment_tree(int n){
		A.resize(n);
		_min.resize((n<<2) + 4);
		_max.resize((n<<2) + 4);
	}

	void init(int node, int i, int j){
		if(i==j)
			_min[node] = _max[node] = A[i];
		else{
			init(node<<1 , i ,(i+j)>>1 );
            init((node<<1)+1 ,((i+j)>>1)+1, j );
			_min[node] = min(_min[node<<1],_min[(node<<1)+1]);
			_max[node] = max(_max[node<<1],_max[(node<<1)+1]);
		}
	}

	int query_min(int node,int a,int b,int i,int j){
		if(a>j or b<i)
			return (1<<30);
		if(a>= i and b <= j)
			return _min[node];
		return min(query_min(node<<1 , a,(a+b)>>1, i,j), query_min((node<<1)+1,((a+b)>>1)+1, b, i,j) );
	}
	int query_max(int node,int a,int b,int i,int j){
		if(a>j or b<i)
			return -(1<<30);
		if(a>= i and b <= j)
			return _max[node];
		return max( query_max(node<<1 , a,(a+b)>>1, i,j),query_max((node<<1)+1,((a+b)>>1)+1, b, i,j) );
	}

	void update(int node, int a,int b, int value,int i,int j){
		if(a>j or b<i)
			return ;
		if(a==b){
			_min[node] = _max[node] = value;
			return;
		}
		update(node<<1, a, (a+b)>>1 ,value,i,j);
		update((node<<1)+1,((a+b)>>1)+1 , b ,value,i,j );
		_min[node] = min(_min[node<<1],_min[(node<<1)+1]);
		_max[node] = max(_max[node<<1],_max[(node<<1)+1]);
	}

};

int main(){
	int n,m;cin>>n>>m;
	vector<Segment_tree> trees(n, Segment_tree(m));
	
	for(int i = 0;i<n; ++i)
		for(int j = 0; j<m; ++j)
			cin>>trees[i].A[j];

	for(int i = 0;i<n; ++i) trees[i].init(1,0,m-1);
	
	int queries;
	cin>>queries;
	for(int i = 0;i< queries;++i){
		char op;
		int a,b,c,d;
		cin>>op;
		if(op == 'q'){
			cin>>a>>b>>c>>d;
			a--;b--;c--;d--;
			int mmin = (1<<30);
			int mmax = -(1<<30);
			for(int i = a; i<=c; ++i){
				mmin = min(mmin,trees[i].query_min(1,0,m-1,b,d));
				mmax = max(mmax, trees[i].query_max(1,0,m-1,b,d));
			}
			cout<<mmax<<" "<<mmin<<endl;
		}else{
			cin>>a>>b>>c;
			a--;b--;
			trees[a].update(1,0,m-1,c,b,b);
		}
	}

	return 0;

}
