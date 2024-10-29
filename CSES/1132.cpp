// 2024-10-25 12:32:11

#include<bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
using namespace std;

const int N = 2e5+50;
vector<int> adj[N];
vector<vector<vector<int>>> dp(N);
void dfs(int rt,int pr=0){
	dp[rt].push_back({0,0});
	for(auto ch:adj[rt]){
		if(ch==pr)	continue;
		dfs(ch,rt);
		dp[rt].push_back({dp[ch][0][0]+1,ch});
	}
	sort(all(dp[rt]));
	reverse(all(dp[rt]));
}
vector<int> ans(N,0);
void dfs2(int rt,int pr=0){
	int curr = ans[pr]+1;
	for(int i=0;i<dp[pr].size();i++){
		if(dp[pr][i][1]!=rt){
			curr = dp[pr][i][0];break;
		}
	}
	cout<<rt<<" "<<curr<<" "<<dp[rt][0][0]<<"\n"; 
	ans[rt] = max(curr+1 , dp[rt][0][0]);
	if(pr)dp[rt].push_back({ans[rt],pr});
	sort(all(dp[rt]));
	reverse(all(dp[rt]));
	for(auto ch:adj[rt]){
		if(ch==pr)	continue;
		dfs2(ch,rt);
	}
}
void basic(){
	int n;cin>>n;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	dfs2(1);
	for(int i=1;i<=n;i++){
		cout<<i<<"\n";
		for(auto x:dp[i]){
			cout<<x[1]<<" "<<x[0]<<"\n";
		}
	}
	for(int i=1;i<=n;i++){
		// cout<<i<<" "<<ans[i]<<"\n";
		cout<<ans[i]<<" ";
	}
}

signed main(){
	int t = 1;
	while(t--){
		basic();
	}
}