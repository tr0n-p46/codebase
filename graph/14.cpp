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
ifstream file("14.txt");
istream &in=file;
#endif

vb visited;

int cnt=0;
int dfs(vii &g,int s) {
	++cnt;
	visited[s]=true;
	REP(i,g[s].size()) {
		int v=g[s][i];
		if(!visited[v])
			dfs(g,v);	
	}
}

int mvertex(vii &g) {
	visited.assign(g.size(),false);
	int v=0;
	REP(i,g.size()) {
		if(!visited[i]) {
			dfs(g,i);
			v=i;
		}	
	}
	visited.assign(g.size(),false);
	cnt=0;
	dfs(g,v);
	if(cnt==g.size())
		return v;
	else 	return -1;
}

int main() {
	fast;
	int v,e;
	in>>v>>e;
	vii g(v,vi(0));
	REP(i,e) {	
		int x,y;
		in>>x>>y;
		g[x].pb(y);
	}
	cout<<mvertex(g)<<endl;
}
