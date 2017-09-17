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
ifstream file("1.txt");
istream &in=file;
#endif

pii res;

bool compare(ii a1,ii a2) {
	return a1.se<a2.se;
}

int select(pii &a) {
	int c=0,n=a.size();
	sort(all(a),compare);
	res.pb(a[0]);
	++c;
	int m=0;
	FOR(i,1,n-1) {
		if(a[i].fi>=a[m].se) {
			res.pb(a[i]);
			m=i;			
			++c;			
		}
	}
	REP(i,res.size()) {
		cout<<res[i].fi<<" "<<res[i].se<<endl;	
	}
	return c;
}

int main() {
	fast;
	int n;
	in>>n;
	pii a;
	while(n--) {
		int s,f;
		in>>s>>f;
		a.pb(mp(s,f));	
	}
	cout<<select(a)<<endl;
}
