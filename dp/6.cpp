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
ifstream file("6.txt");
istream &in=file;
#endif

int maxsub(vii &m) {
	int max=0;
	int x,y;
	int r=m.size();
	int c=m[0].size();
	vii s(r,vi(c));
	REP(i,r) 
		s[i][0]=m[i][0];
	REP(i,c)
		s[0][i]=m[0][i];
	FOR(i,1,r-1) {
		FOR(j,1,c-1) {
			if(m[i][j]==1) {
				s[i][j]=min(s[i-1][j],min(s[i][j-1],s[i-1][j-1]))+1;
				if(s[i][j]>max) {
					max=s[i][j];
					x=i,y=j;				
				}			
			}
			else s[i][j]=0;		
		}	
	}
	FOR(i,x-max+1,x) {
		FOR(j,y-max+1,y) {
			cout<<m[i][j]<<" ";		
		}	
		el;
	}
	return max;
}

int main() {
	fast;
	int r,c;
	in>>r>>c;
	vii m(r,vi(c));
	REP(i,r) {
		REP(j,c) {
			int x;
			in>>x;
			m[i][j]=x;		
		}	
	}
	cout<<maxsub(m)<<endl;
}
