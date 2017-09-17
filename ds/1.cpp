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
#include <numeric>
#include <unordered_set>
#include <unordered_map>

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
#define left(x)				(x<<1|1)
#define right(x)			(left(x)+1)

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
ifstream file("1.txt");
istream &in=file;
#endif

vi a, st;
void build(int node,int l,int r) {
	if(l==r) 
		st[node]=a[l];
	else {
		int mid=(l+r)/2;
		build(2*node,l,mid);
		build(2*node+1,mid+1,r);
		st[node]=st[2*node]+st[2*node+1];	
	}
}

int query(int node, int l,int r,int s,int e) {
	cout<<node<<" "<<a[l]<<" "<<a[r]<<" "<<endl;
	if(l>e || r<s) return 0;
	if(s<=l && e>=r) return st[node];
	int mid=(l+r)/2;
	return query(2*node,l,mid,s,e)+query(2*node+1,mid+1,r,s,e);
}

int main() {
	fast;
	a.pb(-1);
	for(int i=1;i<=11;i+=2) a.pb(i);
	st.assign(3*6,0);
	build(1,1,6);
	pr(a);el;
	pr(st);el;
	cout<<query(1,1,6,2,5)<<endl;
	/*int n,m;	
	in>>n>>m;
	vi a(n); 
	REP(i,n) in>>a[i];
	vi st;
	build(a,st);
	while(m--) {
		int c;
		in>>c;
		if(c==1) {
			int l,r;
			in>>l>>r;
			cout<<query(st,l,r)<<endl;		
		}
		else {
			int i,x;
			in>>i>>x;
			update(a,st,i,x);
		}	
	}*/	
}
