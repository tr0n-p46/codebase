#include <iostream>
#include <limits.h>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <set>
#include <list>
#include <iomanip>

#define FOR(i,a,b)			for(auto i=a;i<=b;i++)
#define FORR(i,a,b)			for(auto i=b;i>=a;i--)
#define REP(i,n)			FOR(i,0,(int)n-1)
#define REPR(i,n)			FORR(i,0,(int)n-1)
#define TR(it,v)			for(auto it:v)
#define	pb				push_back
#define mp				make_pair	
#define all(x)				x.begin(),x.end()
#define	BUG				cout<<"BUG"<<endl
#define INF				INT_MAX
#define fast				ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pr(x)				REP(i,x.size()) cout<<x[i]<<" "
#define prr(x)				REP(i,x.size()) { REP(j,x[i].size()) cout<<x[i][j]<<" ";el;}
#define MOD				1000000007
#define el				cout<<endl
#define fi				first
#define se				second

using namespace std;

typedef stack<int> 			si;
typedef queue<int>			qi;
typedef vector<int>     		vi;
typedef vector<vi >			vii;
typedef pair<int,int>			ii;
typedef pair<int,ii >			edge;
typedef vector<edge >			vpi;
typedef vector<bool>			vb;
typedef vector<long>			vl;
typedef vector<vl >			vll;
typedef pair<long,long>		 	ll;
typedef vector<ll >			vli;
typedef vector<ii >			pii;

#ifndef INP
istream &in=cin;
#else
ifstream file("21.txt");
istream &in=file;
#endif

vii cores;

bool dfs(vii &g,int u,vi &deg,vb &visited,int k) {
	visited[u]=true;
	REP(i,g[u].size()) {
		int v=g[u][i];
		if(deg[u]<k)
			deg[v]--;
		if(visited[v]) continue;
		if(dfs(g,v,deg,visited,k))	
			deg[u]--;	
	}		
	return deg[u]<k;
}

void findcores(vii &g,int k) {
	cores.clear();
	vb visited(g.size(),false);
	vi deg(g.size(),0);
	int mindeg=INF,startv=0;
	REP(i,g.size()) {
		deg[i]=g[i].size();
		if(deg[i]<mindeg) {
			mindeg=deg[i];
			startv=i;		
		}	
	}
	dfs(g,startv,deg,visited,k);
	REP(i,g.size()) {
		if(!visited[i]);
			dfs(g,i,deg,visited,k);	
	}
	cores.assign(g.size(),vi(0));
	REP(i,g.size()) {
		if(deg[i]<k)
			continue;
		REP(j,g[i].size()) {
			int v=g[i][j];
			if(deg[v]<k)
				continue;
			cores[i].pb(v);		
		} 
	}
}

int main() {
	fast;
	int t;
	in>>t;
	while(t--) {
		int v,e,k;
		in>>v>>e>>k;	
		vii g(v,vi(0));
		REP(i,e) {
			int u,w;
			in>>u>>w;
			g[u].pb(w);
			g[w].pb(u);		
		}	
		findcores(g,k);
		REP(i,cores.size()) {
			if(cores[i].size()==0)
				continue;
			cout<<"["<<i<<"] -> ";
			REP(j,cores[i].size()) {
				cout<<cores[i][j]<<" -> ";	
			}
			el;		
		}
		el;
	}
}
