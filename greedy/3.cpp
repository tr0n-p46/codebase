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
ifstream file("3.txt");
istream &in=file;
#endif

vpi res;

bool compare(edge a1,edge a2) {
	return a1.se.se>a2.se.se;
}

int solve(vpi &a) {
	res.clear();
	int n=a.size(),c=0;
	sort(all(a),compare);
	vb slot(n);
	FOR(i,0,n-1) {
		FORR(j,0,min(n,a[i].se.fi)-1) {
			if(!slot[j]) {
				res.pb(a[i]);
				slot[j]=true;			
				++c;		
				break;
			}	
		}		
	}
	return c;
}

int main() {
	fast;
	int t;
	in>>t;
	while(t--) {
		int n;
		in>>n;
		vpi a;
		while(n--) {
			int id,d,p;
			in>>id>>d>>p;
			a.pb(mp(id,mp(d,p)));		
		}	
		cout<<solve(a)<<" ";
		int max=0;
		REP(i,res.size()) {
			max+=res[i].se.se;		
		}
		cout<<max<<endl;
	}
}
