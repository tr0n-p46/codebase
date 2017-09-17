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
ifstream file("4.txt");
istream &in=file;
#endif

int largestsum(vi &a) {
	int n=a.size();
	int max_so_far=0;
	int curr_max=0;
	int s=0,e=0;	
	REP(i,n) {
		curr_max+=a[i];
		if(curr_max<0) {
			curr_max=0;
			s=i+1;
		}
		if(curr_max>max_so_far) {
			max_so_far=curr_max;
			e=i;
		}	
	}
	FOR(i,s,e) {
		cout<<a[i]<<" ";	
	}
	el;
	return max_so_far;
}

int main() {
	fast;
	int n;
	in>>n;
	vi a;	
	REP(i,n) {	
		int x;
		in>>x;
		a.pb(x);	
	}
	cout<<largestsum(a)<<endl;
}
