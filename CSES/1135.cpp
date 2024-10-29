// 2024-10-27 20:44:26

#include<bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
using namespace std;
 
const int N = 2e5+5;
const int l = 17;
vector<int> adj[N];
 
int timer;
int tin[N],tout[N];
// vector<int> tin,tout;
vector<vector<int>> up(N,vector<int>(l+1));
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
	if(u==0 || v==0)	return true;
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
int lev[N];
// vector<int> lev;
void bfs(int rt){
	queue<pair<int,int>> q;
	vector<int> vis(n+1,0);
	q.push({rt,1});
	lev[rt] = 1;
	vis[rt] = 1;
	while(!q.empty()){
		int tp = q.front().first;
		int pos = q.front().second;
		q.pop();
		for(auto &ch:adj[tp]){
			if(!vis[ch]){
				vis[ch] = 1;
				lev[ch] = pos+1;
				q.push({ch,pos+1});
			}
		}
	}
}

void preprocess(){
	// tin.resize(n+1);
	// tout.resize(n+1);
	// lev.resize(n+1);
	timer = 0;
	memset(tin,0,sizeof(tin));
	memset(tout,0,sizeof(tout));
	memset(lev,0,sizeof(lev));
	// l = ceil(log2(n+1));
	// up.assign(n+1,vector<int>(l+1));
	dfs(1,0);
	bfs(1);
}

void basic(){
	int q;cin>>n>>q;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	preprocess();
	while(q--){
		int u,v;cin>>u>>v;
		int a = lca(u,v);
		int ans = lev[u] - lev[a] + lev[v] - lev[a];
		cout<<ans<<"\n";
	}
}
 
signed main(){
	
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int t = 1;
	while(t--){
		basic();
	}
}