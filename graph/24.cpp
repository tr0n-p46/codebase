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
ifstream file("24.txt");
istream &in=file;
#endif

vi key,pi;

void min_heapify(vi &heap,int i) {
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
		min_heapify(heap,smallest);
	}
}

void decrease_key(vi &heap,int v,int k) {
	key[v]=k;
	min_heapify(heap,0);
}

int extract_min(vi &heap) {
	int x=heap[0];
	heap[0]=heap[heap.size()-1];
	heap.pop_back();
	min_heapify(heap,0);
	return x;
}

void make_heap(vi &heap,int n) {
	REP(i,n) {
		heap.pb(i);	
	}
	min_heapify(heap,0);
}

int prims(vector<vector<ii >> &g) {
	key.assign(g.size(),INF);
	pi.assign(g.size(),-1);	
	key[0]=0;
	vi heap;
	make_heap(heap,g.size());
	int wt=0;
	while(heap.size()!=0) {
		int u=extract_min(heap);
		wt+=key[u];	
		REP(i,g[u].size()) {
			int v=g[u][i].fi;
			int w=g[u][i].se;
			if(key[v]>w) {
				decrease_key(heap,v,w);
				pi[v]=u;			
			}		
		}
	}
	return wt;
}

int main() {
	fast;
	int v,e;
	in>>v>>e;
	vector<vector<ii >> g(v,vector<ii >(0));
	REP(i,e) {
		int x,y,w;
		in>>x>>y>>w;
		g[x].pb(mp(y,w));
		g[y].pb(mp(x,w));	
	}
	cout<<prims(g)<<endl;
}
