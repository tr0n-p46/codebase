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
ifstream file("16.txt");
istream &in=file;
#endif

int main() {
	fast;	
	int n;
	in>>n;
	vi a(n);
	REP(i,n) in>>a[i];
	sort(all(a),greater<int>());
	long max=0;
	int l1,m1,k1;
	REP(i,n-2) {
		int l=a[i];
		int m=a[i+1];
		int k=a[i+2];
		if(l>=m+k || m>=l+k || k>=l+m) continue;
		if((long)l+m+k>max) {
			max=(long)l+m+k;	
			k1=k,m1=m,l1=l;
		}
	}
	if(max==0) cout<<"-1";
	else cout<<k1<<" "<<m1<<" "<<l1;
}
