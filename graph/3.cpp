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
typedef pair<long long,int>		ll;
typedef vector<ll >			vli;
typedef vector<long long>		vln;
typedef vector<ii >			pii;

#ifndef INP
istream &in=cin;
#else
ifstream file("3.txt");
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
			if(color[v]==-1) {
				q.push(v);
				color[v]=1-color[u];
			}
			else if(color[u]==color[v])
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

int main() {
	fast;
	int v,e;
	in>>v>>e;
	vii g(v,vi(0));
	REP(i,e) {
		int u,w;
		in>>u>>w;
		g[u].pb(w);
		g[w].pb(u);	
	}
	if(isBipartite(g))
		cout<<"yes";
	else
		cout<<"no";
	el;
}
