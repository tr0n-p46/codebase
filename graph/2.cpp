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
ifstream file("2.txt");
istream &in=file;
#endif

int solve(vii &w,bool directed) {
	int count=0;
	REP(i,w.size()) {
		REP(j,w.size()) {
			REP(k,w.size()) {	
				if(w[i][j] && w[j][k] && w[k][i])
					++count;			
			}		
		}	
	}
	return directed?(count/3):(count/6);
}

int main() {
	fast;
	int v,e;
	in>>v>>e;
	vii w(v,vi(v,0));
	REP(i,e) {
		int u,v;
		in>>u>>v;
		w[u][v]=1;	
	}
	bool directed=true;
	cout<<solve(w,directed)<<endl;
}

