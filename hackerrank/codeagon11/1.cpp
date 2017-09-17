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
ifstream file("1.txt");
istream &in=file;
#endif

vi matchR,matchL;

bool bpm(vii &g,int u,vb &seen) {
	REP(v,g[0].size()) {
		if(!g[u][v] || seen[v]) continue;
		seen[v]=true;
		if(matchR[v]==-1 || bpm(g,matchR[v],seen)) {
			matchR[v]=u;
			matchL[u]=v;
			return true;		
		}
	}
	return false;
}

int maxbpm(vii &g) {
	int m=g.size();
	int n=g[0].size();
	matchL.assign(m,-1);
	matchR.assign(n,-1);
	int max=0;	
	REP(i,m) {
		vb seen(n,false);
		if(bpm(g,i,seen))
			++max;	
	}
	return max;
}

bool validate(ii e,ii p) {
	if(e.fi==p.fi || e.se==p.se)
		return true;
	if(abs(e.fi-p.fi)==abs(e.se-p.se))
		return true;
	return false;
}

int main() {
	int m=pow(10,9);
	fast;
	int q;
	in>>q;
	while(q--) {
		int x,y;
		in>>x>>y;
		pii e;
		REP(i,x) {
			int u,v;
			in>>u>>v;
			e.pb(mp(u,v));		
		}	
		pii p;
		REP(i,y) {
			int u,v;
			in>>u>>v;
			p.pb(mp(u,v));		
		}
		vii g(x,vi(y));
		REP(i,x) {
			REP(j,y) {
				if(validate(e[i],p[j]))
					g[i][j]=1;
			}		
		}
		cout<<maxbpm(g)<<endl;
	}
}
