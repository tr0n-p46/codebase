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
ifstream file("5.txt");
istream &in=file;
#endif

int solve(int n) {
	int i2=0,i3=0,i5=0;
	int val2=2,val3=3,val5=5;
	vi val(n+1);
	val[0]=1;
	FOR(i,1,n) {
		
		val[i]=min(val2,min(val3,val5));
		if(val2==val[i]) {
			++i2;
			val2=val[i2]*2;
		}
		if(val3==val[i]) {
			++i3;
			val3=val[i3]*3;
		}
		if(val5==val[i]) {
			++i5;
			val5=val[i5]*5;
		}
	}
	return val[n-1];
}

int main() {
	fast;
	int t;
	in>>t;
	while(t--) {
		int n;
		in>>n;
		cout<<solve(n)<<endl;	
	}
}
