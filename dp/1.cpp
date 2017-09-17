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
ifstream file("1.txt");
istream &in=file;
#endif

vii f(2,vi(2,0));


void multiply(vii &a,vii &b) {
	int x=a[0][0]*b[0][0]+a[0][1]*b[1][0];
	int y=a[0][0]*b[0][1]+a[0][1]*b[1][1];
	int z=a[1][0]*b[0][0]+a[1][1]*b[1][0];
	int w=a[1][0]*b[0][1]+a[1][1]*b[1][1];
	a[0][0]=x;
	a[0][1]=y;
	a[1][0]=z;
	a[1][1]=w;
}

void multiplyN(int n) {
	vii res=f;
	REP(i,n-1) {
		multiply(res,f);	
	}
	f=res;
}

int fib(int n) {
	f[0][0]=f[0][1]=f[1][0]=1;
	f[1][1]=0;
	multiplyN(n-1);
	return f[0][0];
}

int main() {
	fast;
	int n;
	in>>n;
	cout<<fib(n)<<endl;
}
