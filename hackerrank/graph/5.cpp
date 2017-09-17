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
ifstream file("5.txt");
istream &in=file;
#endif

void makegraph(vii &a,vii&g) {
	REP(i,a.size()) {
		REP(j,a[i].size()) {
			if(i-1>=0 && a[i-1][j]==1) {
				g[i-1][j]=g[i][j]			
			}		
		}	
	}
}

int main() {
	fast;
	int n,m,k,q;
	in>>n>>m>>k>>q;
	vii a(n,vi(m));	
	REP(i,n) REP(j,m) in>>a[i][j];
	int ex,ey,sx,sy,tx,ty;
	in>>ex>>ey>>sx>>sy>>tx>>ty;
	vii g(n,vi(m));
	makegraph(a,g);
}
