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
ifstream file("1.txt");
istream &in=file;
#endif

int cnt;

int dfs(vii &g,int s,vi &c) {
	if(g[s].size()==0) {
		c[s]=0;	
		return 0;
	}
	int count=0;
	REP(i,g[s].size()) {
		int v=g[s][i];
		count+=dfs(g,v,c)+1;	
	}
	c[s]=count;
	return count;
}

void dfs2(vii &g,int s,vi &c) {
	REP(i,g[s].size()) {
		int v=g[s][i];
		dfs2(g,v,c);	
		if(c[v]%2!=0)
			++cnt;
	}
}

void solve(vii &g) {
	vi c(g.size(),0);
	dfs(g,0,c);
	cnt=0;
	dfs2(g,0,c);
	cout<<cnt<<endl;
}

int main() {
	fast;
	int v,e;
	in>>v>>e;
	vii g(v,vi(0));
	REP(i,e) {
		int x,y;
		in>>x>>y;
		--x;
		--y;
		g[y].pb(x);	
	}
	solve(g);	
}
