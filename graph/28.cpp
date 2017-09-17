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
ifstream file("28.txt");
istream &in=file;
#endif

void floyd(vii &w) {
	vii d(w);
	int n=w.size();
	vii pi(n,vi(n));
	REP(i,n) {
		REP(j,n) {
			if(i==j) 
				pi[i][j]=-1;
			else	pi[i][j]=i;
		}	
	}
	REP(k,n) {
		vii dk(n,vi(n)),pik(pi);
		REP(i,n) {
			REP(j,n) {	
				dk[i][j]=min(d[i][j],(d[i][k]==INF||d[k][j]==INF)?INF:d[i][k]+d[k][j]);	
				if(dk[i][j]!=d[i][j]) 
					pik[i][j]=pik[k][j];
			}	
		}
		d=dk;
		pi=pik;
	}
	prr(d);
	el;
	prr(pi);
}

int main() {
	fast;
	int v,e;
	in>>v>>e;
	vii w(v,vi(v));
	REP(i,v) {
		REP(j,v) {
			if(i!=j)
				w[i][j]=INF;		
		}	
	}
	REP(i,e) {
		int u,v,wt;
		in>>u>>v>>wt;
		w[u][v]=wt;	
	}
	floyd(w);
}
