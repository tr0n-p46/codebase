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
ifstream file("3.txt");
istream &in=file;
#endif

vi p,ran;
int cnt;

int find_set(int x) {
	return x==p[x]?p[x]:find_set(p[x]);
}

void link(int x,int y) {
	if(ran[x]>ran[y])
		p[y]=x;
	else {
		p[x]=y;
		if(ran[x]==ran[y])
			++ran[y];	
	}
}

void union_set(int x,int y) {
	link(find_set(x),find_set(y));
}

void make_set(int n) {
	REP(i,n) {
		p.pb(i);
		ran.pb(0);	
	}
}

int kruskal(vpi &edges,int n) {
	make_set(n);
	int wt=0;
	sort(all(edges));
	REP(i,edges.size()) {
		int x=edges[i].se.fi;
		int y=edges[i].se.se;
		int w=edges[i].fi;
		if(find_set(x)!=find_set(y)) {
			union_set(x,y);	
			wt+=w;
		}
		else ++cnt;
	}
	return wt;
}

vb visited;
vi cmp;
int val;

void dfs(vii &g,int s) {
	visited[s]=true;	
	++val;
	REP(i,g[s].size()) {
		if(!visited[g[s][i]])
			dfs(g,g[s][i]);
	}
}

void dfsutil(vii &g) {
	visited.assign(g.size(),false);
	REP(i,g.size()) {
		if(!visited[i]) {
			val=0;
			dfs(g,i);
			cmp.pb(val);			
		}
	}
}

int main() {
	fast;
	int v,e;
	in>>v>>e;
	vpi edges;
	vii g(v,vi(0));
	REP(i,e) {
		int x,y;
		in>>x>>y;
		edges.pb(mp(1,mp(--x,--y)));	
		g[x].pb(y);
		g[y].pb(x);
	}
	cnt=0;	
	kruskal(edges,v);
	dfsutil(g);
	long val=0;
	if(cnt>=2) {
		REP(i,cmp.size()) val=(long)val+(long)cmp[i]*(cmp[i]-1);	
	}
	else {
		sort(all(cmp));
		if(cnt==1) {
			REP(i,cmp.size()) {	
				if(cmp[i]>=2) {
					--cmp[i];
					break;					
				}
			}
			REP(i,cmp.size()) val=(long)val+(long)cmp[i]*(cmp[i]-1);	
		}
		else {
			REP(i,cmp.size()) {	
				if(cmp[i]>=3) {
					--cmp[i];
					break;					
				}
			}
			REP(i,cmp.size()) {	
				if(cmp[i]>=2) {
					--cmp[i];
					break;					
				}
			}
			
			REP(i,cmp.size()) val=(long)val+(long)cmp[i]*(cmp[i]-1);
		}
	}
	cout<<(long)val<<endl;
}
