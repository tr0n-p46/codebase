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
ifstream file("2.txt");
istream &in=file;
#endif

void primeFactors(int n,vi &factors) {
    factors.pb(1);
    while (n%2 == 0)
    {
        factors.pb(2);
        n = n/2;
    }
    FOR(i,3,sqrt(n))
    {
        while (n%i == 0)
        {
            factors.pb(i);
            n = n/i;
        }
	++i;
    }
    if (n > 2)
        factors.pb(n);
}

int main() {
	fast;
	int t;
	in>>t;
	while(t--) {
		int n,q;
		in>>n>>q;
		vl a(n+1);
		FOR(i,1,n) {
			long x;
			in>>x;
			a[i]=x;	
		}
		vector<long long> sum(n+1);
		FOR(i,1,n) {
			sum[i]=a[i]*a[i];		
		}
		FORR(i,1,n) {
			vi factors;
			primeFactors(i,factors);
			REPR(j,factors.size()) {
				if(factors[j]==i || (j<=factors.size()-2 && factors[j]==factors[j+1]))
					continue;
				sum[factors[j]]+=sum[i];
			}		
		}
		while(q--) {
			int c;
			in>>c;
			if(c==1) {
			}
			else {
			}			
		}
	}
}
