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
ifstream file("27.txt");
istream &in=file;
#endif

vi d,pi;

bool bellman(vpi &edges,int n,int s) {
	d.assign(n,INF);
	pi.assign(n,-1);
	d[s]=0;
	REP(k,n-1) {
		REP(i,edges.size()) {
			int w=edges[i].fi;
			int u=edges[i].se.fi;
			int v=edges[i].se.se;
			if(d[u]!=INF && d[v]>d[u]+w) {
				d[v]=d[u]+w;
				pi[v]=u;		
			}			
		}	
	}
	REP(i,edges.size()) {
		int w=edges[i].fi;
		int u=edges[i].se.fi;
		int v=edges[i].se.se;
		if(d[u]!=INF && d[v]>d[u]+w)
			return false;		
	}
	return true;
}

int main() {
	fast;
	int v,e,s;
	in>>v>>e>>s;
	vpi edges;
	REP(i,e) {
		int x,y,w;
		in>>x>>y>>w;
		edges.pb(mp(w,mp(x,y)));	
	}
	if(bellman(edges,v,s))
		cout<<"no negative weight cycle"<<endl;
	else	cout<<"negative weight cycle present"<<endl;
	pr(d);
	el;
}
