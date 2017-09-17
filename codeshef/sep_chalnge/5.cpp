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
#include <unordered_set>

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
ifstream file("5.txt");
istream &in=file;
#endif

long xxor(long x,long y) {
	return (x|y)&(~x|~y);
}

long dfs(vii &g,int s,vl &d,vb &visited) {
	visited[s]=true;
	long sum=d[s];
	REP(i,g[s].size()) {
		if(!visited[g[s][i]]) {
			sum = xxor(sum,dfs(g,g[s][i],d,visited));		
		}
	}
	return d[s]=sum;
}

void process(vii &g,vl &d) {
	vb visited(g.size(),false);	
	dfs(g,0,d,visited);
}

int main() {
	fast;	
	int n,q;	
	in>>n>>q;
	vii g(n,vi(0));
	REP(i,n-1) {
		int u,v;	
		in>>u>>v;
		g[u].pb(v);
		g[v].pb(u);	
	}
	vl d(n);
	REP(i,n) in>>d[i];
	vl t(q);
	REP(i,q) in>>t[i];
	int ind=0;
	REP(i,q) {
		process(g,d);
		if(i+1==t[ind]) {
			++ind;
			cout<<d[0]<<endl;		
		}
	}
}
