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
#include <numeric>
#include <unordered_set>
#include <unordered_map>

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
ifstream file("1.txt");
istream &in=file;
#endif

int main() {
	fast;	
	string s;
	in>>s;
	int n=s.length();
	int o_d=0,e_d=0;
	int val=0;
	REPR(i,s.length()) {
		if((n-i)%2!=0 && s[i]=='1') ++o_d;
		else if((n-i)%2==0 && s[i]=='1') ++e_d;	
		val+=(s[i]-'0')*pow(2,n-i-1);
	}
	int c=abs(o_d-e_d)%3;
	if(c==0) cout<<val;
	else if(c==1) {
		int index=-1;
		if(o_d>e_d) {
			if(n/2!=e_d) {
				REP(i,s.length()) {
					if((n-i)%2==0 && s[i]=='0') {index=n-i-1;break;}
				}		
				cout<<val+pow(2,index);	
			}
			else if(o_d!=0){
				REPR(i,s.length()) {
					if((n-i)%2!=0 && s[i]=='1') {index=n-i-1;break;}
				}		
				cout<<val-pow(2,index);	
			}					
		}
		if(e_d>o_d) {
			if(ceil(n/2.0)!=o_d) {
				REP(i,s.length()) {
					if((n-i)%2!=0 && s[i]=='0') {index=n-i-1;break;}
				}		
				cout<<val+pow(2,index);	
			}
			else if(e_d!=0){
				REP(i,s.length()) {
					if((n-i)%2==0 && s[i]=='1') {index=n-i-1;break;}
				}		
				cout<<val-pow(2,index);	
			}
		}
		if(index==-1) cout<<index;
	}
	else cout<<"-1";
}
