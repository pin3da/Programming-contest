using namespace std;
#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>

template <class T> int to_int(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }
/**
N^2 approach, doesn't works for this problem
vector<int> lis(vector<int> &nums){
	vector<int> L(nums.size(),1);
	for(int i=0;i < nums.size();++i)
		for(int j=i+1;j < nums.size();++j)
			if(nums[j] > nums[i])
				L[j] = max(L[i] + 1, L[j]);
				
	int mmax = 0;
	int pos = 0;
	for(int i=0;i < nums.size();++i)
		if(L[i] > mmax){
			mmax = L[i];
			pos = i;
		}
	
	vector<int>	ans(mmax);
	int index = 0;
	while(pos >= 0 and mmax){
		if(mmax == L[pos]){
			ans[index++] = nums[pos];
			mmax--;
		}
		pos--;
	}
	return ans;
}
*/


// Nlogk approach
void find_lis(vector<int> &a, vector<int> &b){
  vector<int> p(a.size());
  int u, v;
  if (a.empty()) return;
  b.push_back(0);
  for (size_t i = 1; i < a.size(); i++){
    // If next element a[i] is greater than
    // last element of current
    // longest subsequence a[b.back()],
    // just push it at back of "b" and continue
    if (a[b.back()] < a[i]){
      p[i] = b.back();
      b.push_back(i);
      continue;
    }
    // Binary search to find the smallest 
    // element referenced
    //by b which is just bigger than a[i]
    // Note : Binary search is performed on b
    // (and not a).
    //Size of b is always <=k and hence
    //contributes O(log k) to complexity.
    for (u = 0, v = b.size()-1; u < v;){
      int c = (u + v) / 2;
      if (a[b[c]] < a[i]) u=c+1; else v=c;
    }
    // Update b if new value is smaller
    // then previously referenced value
    if (a[i] < a[b[u]]){
      if (u > 0) p[i] = b[u-1];
      b[u] = i;
    }
  }
  for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
}


int main(){
	string line;
	getline(cin,line);
	int tc = to_int(line);
	getline(cin,line);
	bool first = true;
	while(tc--){
		if(!first)cout<<endl;
		first = false;
		int num;
		vector<int> nums;
		while(getline(cin,line) and line.size()){
			num = to_int(line);
			nums.push_back(num);
		}
		vector<int> ans; 
		find_lis(nums,ans);
		cout<<"Max hits: "<<ans.size()<<endl;
		for(int i=0;i<ans.size();++i)
			cout<<nums[ans[i]]<<endl;
	}
	return 0;
}
