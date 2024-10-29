// 2024-10-23 10:27:43

#include<bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
using namespace std;
const int N = 2e5+50;
vector<int> adj[N];
vector<int> ans(N,0);
void dfs(int rt,int pr=0){
	for(auto ch:adj[rt]){
		if(ch==pr)	continue;
		dfs(ch,rt);
		ans[rt]+=(ans[ch]+1);
	}
}
void basic(){
	int n;cin>>n;
	for(int i=2;i<=n;i++){
		int u;cin>>u;
		adj[u].push_back(i);
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
}

signed main(){
	int t = 1;
	while(t--){
		basic();
	}
}