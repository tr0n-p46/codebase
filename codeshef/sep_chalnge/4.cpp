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
ifstream file("4.txt");
istream &in=file;
#endif

bool flag=true;

bool dfs(vvi &g,int s,vb &visited,vb &recstack,int sum) {
	visited[s]=true;
	recstack[s]=true;
	cout<<"s:"<<s;
	REP(i,g[s].size()) {
		int v=g[s][i].fi;
		cout<<"v:"<<v;
		sum+=g[s][i].se;
		cout<<"w:"<<sum<<endl;
		if(!visited[v] && dfs(g,v,visited,recstack,sum) || recstack[v]) {
			if(sum!=0) return true;
		}
	}
	recstack[s]=false;
	return false;
}

bool isConsistent(vvi &g) {
	vb visited(g.size(),false);
	vb recstack(g.size(),false);
	REP(i,g.size()) {
		int sum=0;
		if(!visited[i] && dfs(g,i,visited,recstack,sum))
			return false;	
	}
	return true;
}

void solve(vvi &g) {
	flag=isConsistent(g);
	if(flag) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
}

int main() {
	fast;	
	int t;
	in>>t;
	while(t--) {
		int n,q;
		in>>n>>q;
		vvi g(n,pii(0));
		REP(i,q) {
			int u,v,w;
			in>>u>>v>>w;
			--u,--v;
			if(u==v && w!=0) flag=false;	
			g[u].pb(mp(v,w));
			g[v].pb(mp(u,-w));		
		}
		solve(g);
	}
}
