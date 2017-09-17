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
typedef vector<pii >			vvi;

#ifndef INP
istream &in=cin;
#else
ifstream file("30.txt");
istream &in=file;
#endif

void dfs(vvi &g,int s,vb &visited,si &top) {
	visited[s]=true;
	REP(i,g[s].size()) {
		int v=g[s][i].fi;
		if(!visited[v]) 
			dfs(g,v,visited,top);	
	}
	top.push(s);
}

void toposort(vvi &g,si &top) {
	vb visited(g.size(),false);
	REP(i,g.size()) {
		if(!visited[i])
			dfs(g,i,visited,top);	
	}	
}

void shortpath(vvi &g,int s,vi &d) {
	d.assign(g.size(),INF);
	d[s]=0;
	si top;
	toposort(g,top);
	while(top.top()!=s) 
		top.pop();
	while(!top.empty()) {
		int u=top.top();
		top.pop();
		REP(j,g[u].size()) {
			int v=g[u][j].fi;
			int w=g[u][j].se;
			if(d[u]!=INF && d[v]>d[u]+w)		
				d[v]=d[u]+w;
		}	
	}
}

int main() {
	fast;
	int v,e;
	in>>v>>e;
	vvi g(v,pii(0));
	REP(i,e) {
		int x,y,w;
		in>>x>>y>>w;
		g[x].pb(mp(y,w));	
	}
	vi d;
	shortpath(g,1,d);
	pr(d);
	el;	
}
