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
ifstream file("match1.txt");
istream &in=file;
#endif

bool compare(ii a1,ii a2) {
	return a1.se>a2.se;
}

int solve(pii &bc,int n) {
	int res=0;
	sort(all(bc),compare);
	int sum=0;
	REP(i,bc.size()) {
		sum+=bc[i].fi;
		//cout<<bc[i].fi<<"\t"<<(int)bc[i].fi*bc[i].se<<"\t"<<(int)sum<<endl;
	}
	//cout<<(int)n<<endl;
	REP(i,bc.size()) {
		if(n<=bc[i].fi) {
			res+=bc[i].se*n;
			break;		
		}	
		res+=bc[i].fi*bc[i].se;
		n-=bc[i].fi;
	}
	return res;
}

int main() {
	fast;
	int n,c;
	in>>n>>c;
	pii bc;
	REP(i,c) {
		int b,m;
		in>>b>>m;
		bc.pb(mp(b,m));	
	}
	cout<<solve(bc,n)<<endl;
}
