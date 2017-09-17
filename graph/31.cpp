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
ifstream file("31.txt");
istream &in=file;
#endif

int maxset(vii &g,int s,vb &visited,vi &liss) {
	visited[s]=true;
	if(liss[s]) return liss[s];
	if(!g[s].size()) return (liss[s]=1);
	int liss_incl=1,liss_excl=0;
	REP(i,g[s].size()) {
		int v=g[s][i];
		if(visited[v]) continue;
		liss_excl+=maxset(g,v,visited,liss);	
	}	
	REP(i,g[s].size()) {
		int v=g[s][i];
		if(visited[v]) continue;
		REP(j,g[v].size()) {
			if(visited[g[v][j]]) continue;
			liss_incl+=maxset(g,g[v][j],visited,liss);		
		}	
	}
	return liss[s]=max(liss_incl,liss_excl);
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
		g[y].pb(x);	
	}
	vb visited(v,false);
	vi liss(v,0);
	cout<<maxset(g,5,visited,liss)<<endl;	
}
