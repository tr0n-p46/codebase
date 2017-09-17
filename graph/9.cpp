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
ifstream file("9.txt");
istream &in=file;
#endif

vi p,ran;

int find_set(int x) {
	return x==p[x]?p[x]:find_set(p[x]);
}

void link(int x,int y) {
	if(ran[x]>ran[y]) {
		p[y]=x;	
	}
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

bool isCyclic(vpi &edges,int n) {
	make_set(n);
	REP(i,edges.size()) {
		int x=edges[i].se.fi;
		int y=edges[i].se.se;
		if(find_set(x)==find_set(y))
			return true;
		union_set(x,y); 				
	}
	return false;
}

int main() {
	fast;
	int v,e;
	in>>v>>e;
	vpi edges;
	REP(i,e) {	
		int u,w;
		in>>u>>w;
		edges.pb(mp(1,mp(u,w)));
	}
	if(isCyclic(edges,v))
		cout<<"cycle present"<<endl;
	else	cout<<"cycle not present"<<endl;
}
