#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) rep(i,0,n)

typedef vector<int> vi;

//one dimension
// Creates a zero-initialized Fenwick tree for n elements.
vector < int > create(int n){
  return vector < int > (n, 0);
}
// Returns sum of elements with indexes a..b, inclusive
int query(const vector < int > & tree, int a, int b){
  if (a == 0)  {
    int sum = 0;
    for (; b >= 0; b = (b & (b + 1)) - 1)
      sum += tree[b];
    return sum;
  }
  else  {
    return query(tree, 0, b) - query(tree, 0, a - 1);
  }
}
// Increases value of k-th element by inc.
void increase(vector < int > & tree, int k, int inc){
  for (; k < (int) tree.size(); k |= k + 1)
    tree[k] += inc;
}

int main(){
  int n, k;
  while(cin >> n >> k){
    vi tree_negative(n+1);
    vi tree_zero(n+1);
    
    vi X;
    X.push_back(0);
    
    REP(i,n){
      int xi;
      cin >> xi;
      X.push_back(xi);
      if(xi == 0) increase(tree_zero,i+1,1);
      if(xi < 0) increase(tree_negative,i+1,1);
    }

    string out = "";
    REP(i,k){
      string cmd;
      cin >> cmd;
      if(cmd == "C"){
	int i, v;
	cin >> i >> v;

	if(X[i] == 0 && v != 0) increase(tree_zero,i,-1);
	if(X[i] != 0 && v == 0) increase(tree_zero,i,1);

	if(X[i] < 0 && v >= 0) increase(tree_negative,i,-1);
	if(X[i] >= 0 && v < 0) increase(tree_negative,i,1);
	X[i] = v;
      }else if(cmd == "P"){
	int i, j;
	cin >> i >> j;

	int is_zero = query(tree_zero,i,j);
	int is_negative = query(tree_negative,i,j) % 2;
	
	if(is_zero) out += "0";
	else if(is_negative) out += "-";
	else out += "+";
      }else
	assert(false);
    }
    cout << out << endl;
  }

  return 0;
}
