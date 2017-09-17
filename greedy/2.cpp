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
typedef pair<long long,int>		ll;
typedef vector<ll >			vli;
typedef vector<long long>		vln;
typedef vector<ii >			pii;

#ifndef INP
istream &in=cin;
#else
ifstream file("2.txt");
istream &in=file;
#endif

pii res;

int solve(ii e) {
	res.clear();
	int c=0;
	while(e.fi!=0) {
		int dr=ceil((float)e.se/e.fi);
		int nr=1;
		ii nxt(mp(nr,dr));
		res.pb(nxt);
		e.fi=dr*e.fi-e.se;	
		e.se=dr*e.se;		
		++c;	
	}
	REP(i,res.size()) {
		cout<<res[i].fi<<"/"<<res[i].se<<" + ";		
	}
	el;
	return c;
}

int main() {
	fast;
	int t;
	in>>t;
	while(t--) {
		int nr,dr;
		char ch;
		in>>nr>>ch>>dr;
		ii e(mp(nr,dr));
		cout<<solve(e)<<endl; 	
	}
}
