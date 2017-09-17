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
ifstream file("4.txt");
istream &in=file;
#endif

void min_heapify(vi &heap,int i,vi &key) {
	int l=(i<<2)+1;	
	int r=l+1;
	int smallest=0;
	if(l<heap.size() && key[heap[l]]<key[heap[i]]) 
		smallest=l;
	else smallest=i;
	if(r<heap.size() && key[heap[r]]<key[heap[smallest]]) 
		smallest=r;
	if(smallest!=i) {
		int temp=heap[i];
		heap[i]=heap[smallest];	
		heap[smallest]=temp;
		min_heapify(heap,smallest,key);
	}
}

void decrease_key(vi &heap,int v,int k,vi &key) {
	key[v]=k;
	min_heapify(heap,0,key);
}

int extract_min(vi &heap,vi &key) {
	int x=heap[0];
	heap[0]=heap[heap.size()-1];
	heap.pop_back();
	min_heapify(heap,0,key);
	return x;
}

void make_heap(vi &heap,int n,vi &key) {
	REP(i,n) {
		heap.pb(i);	
	}
	min_heapify(heap,0,key);
}

void dijkstra(vvi &g,int s,vi &d) {
	d.assign(g.size(),INF);
	d[s]=0;
	vi heap;
	make_heap(heap,g.size(),d);
	while(heap.size()!=0) {
		int u=extract_min(heap,d);
		REP(i,g[u].size()) {
			int v=g[u][i].fi;
			int w=g[u][i].se;
			if(d[u]!=INF && d[v]>d[u]+w) {
				decrease_key(heap,v,w+d[u],d);
			}		
		}
	}
}

int main() {
	fast;
	int t;
	in>>t;
	while(t--) {
		int n,m;
		in>>n>>m;
		vvi g(n,pii(0));
		REP(i,m) {
			int u,v,w;
			in>>u>>v>>w;
			--u,--v;
			g[u].pb(mp(v,w));
			g[v].pb(mp(u,w));		
		}	
		int s;
		in>>s;
		--s;
		vi d;
		dijkstra(g,s,d);
		REP(i,d.size()) {
			if(d[i]==INF) 
				cout<<-1<<" ";
			else if(i!=s)
				cout<<d[i]<<" ";		
		}
		el;
	}
}
