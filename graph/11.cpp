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
ifstream file("11.txt");
istream &in=file;
#endif

si p;
vb visited;

void dfs(vii &g,int s,int t) {
	visited[s]=true;
	p.push(s);
	if(s==t) {
		while(!p.empty()) {
			cout<<p.top()<<" ";
			p.pop();		
		}
	}
	REP(i,g[s].size()) {
		int v=g[s][i];
		if(!visited[v])
			dfs(g,v,t);
	}
	if(!p.empty())
		p.pop();
}

int main() {
	fast;
	int v,e,s,t;
	in>>v>>e>>s>>t;
	vii g(v,vi(0));
	REP(i,e) {	
		int u,w;
		in>>u>>w;
		g[u].pb(w);
		g[w].pb(u);
	}
	visited.assign(v,false);
	dfs(g,s,t);
}
