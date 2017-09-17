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
ifstream file("16.txt");
istream &in=file;
#endif

vi color;

bool bfs(vii &g,int s) {
	qi q;
	q.push(s);
	color[s]=1;
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		REP(i,g[u].size()) {
			int v=g[u][i];
			if(v!=1)
				continue;
			if(color[i]==-1) {
				q.push(i);
				color[i]=1-color[u];
			}
			else if(color[u]==color[i])
				return false;
		}		
	}
	return true;
}

bool isBipartite(vii &g) {
	int n=g.size();
	color.assign(n,-1);
	REP(i,n) {
		if(color[i]==-1) {
			if(!bfs(g,i))
				return false;		
		}	
	}
	return true;	
}

vi parent;

bool bfs2(vii &g,int s,int t) {
	qi q;
	vb visited(g.size(),false);
	parent.assign(g.size(),-1);
	q.push(s);
	visited[s]=true;
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		REP(i,g.size()) {
			int v=g[u][i];
			if(!visited[i] && v>0) {
				q.push(i);
				visited[i]=true;
				parent[i]=u;
				//cout<<"parent of "<<i<<" is "<<u<<endl;
			}
		}		
	}
	return visited[t];
}

int maxflow(vii &g,int s,int t) {
	int max_flow=0;
	vii gf(g);
	while(bfs2(gf,s,t)) {
		int path_flow=1;
		for(int i=t;i!=s;i=parent[i]) {
			path_flow=min(path_flow,gf[parent[i]][i]);	
		}
		for(int i=t;i!=s;i=parent[i]) {
			gf[parent[i]][i]-=path_flow;
			gf[i][parent[i]]+=path_flow;		
		}
		max_flow+=path_flow;
	}
	return max_flow;
}

int main() {
	fast;
	int v,e;
	in>>v>>e;
	vii g(v,vi(v));
	REP(i,e) {
		int u,w;
		in>>u>>w;
		g[u][w]=1;		
	}
	isBipartite(g);
	vii gf(v+2,vi(v+2));
	REP(i,v) {
		REP(j,v) {
			gf[i][j]=g[i][j];		
		}	
	}
	REP(i,v) {
		if(color[i]==1)
			gf[v][i]=1;
		else	gf[i][v+1]=1;
	}
	cout<<maxflow(gf,v,v+1);
}
