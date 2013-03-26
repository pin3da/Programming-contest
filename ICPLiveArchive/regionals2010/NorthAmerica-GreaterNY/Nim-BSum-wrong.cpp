vector<int> to_num(int t,int base){
	vector<int>	ans;
	while(t){
		ans.push_back(t%base);
		t/=base;
	}
	return ans;
}

int to_dec(vector<int> n,int base){
	int ans = 0;
	reverse(all(n));
	for(int i=0;i<n.size();++i){
		ans*=base;
		ans+=n[i];
	}
	return ans;
}


int solve2(int b,int x,int y){
	vector<int>	n1 = to_num(x,b);
	vector<int>	n2 = to_num(y,b);
	int tope = min(n1.size(),n2.size());
	vector<int> ans(max(n1.size(),n2.size()));
	for(int i = 0;i<tope;++i){
		ans[i] = ((n1[i]+n2[i])%b);
	}	
	if(n2.size() > n1.size())
		for(int i = n1.size();i<n2.size();++i)
			ans[i] = (n2[i]);
	else
		for(int i = n2.size();i<n1.size();++i)
			ans[i] = (n2[i]);
	return to_dec(ans,b);

}
