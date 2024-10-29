// 2024-10-27 12:12:39

#include<bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
using namespace std;

const int N = 2e5+50;
const int l = 16;

vector<int> adj[N];

int timer;
vector<int> tin(N),tout(N);
vector<vector<int>> up(N,vector<int>(l,0));
int n;

void dfs(int rt,int pr){
	tin[rt] = ++timer;
	up[rt][0] = pr;
	for(int i=1;i<=l;i++){
		int old = up[rt][i-1];
		up[rt][i] = up[old][i-1];
	}
	for(int ch:adj[rt]){
		if(ch!=pr)dfs(ch,rt);
	}
	tout[rt] = ++timer;
}
bool is_anc(int u,int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
int lca(int u,int v){
	if(is_anc(u,v))	return u;
	if(is_anc(v,u))	return v;
	for(int i=l;i>=0;i--){
		if(!is_anc(up[u][i],v))	u = up[u][i];
	}
	return up[u][0];
}

void preprocess(int root){
	dfs(root,root);
}

void basic(){
	int q;cin>>n>>q;
	for(int u=2;u<=n;u++){
		int v;cin>>v;
		adj[v].push_back(u);
	}
	preprocess(1);
	while(q--){
		int u,v;cin>>u>>v;
		cout<<lca(u,v)<<"\n";
	}
}

signed main(){
	int t = 1;
	while(t--){
		basic();
	}
}